#include <stdio.h>

#include <pthread.h>

 

#define MAX 5

 

int buffer[MAX]; //생성한 값을 넣는 버퍼

int fill_ptr=0;

int use_ptr=0;

int count=0;

int loops=100;

 

//typedef struct __

int pthread_create(   pthread_t * thread, //쓰레드 생성

      const pthread_attr_t * attr,

         void * (*start_routine)(void*),

         void * arg);

 

void put(int value){ //생산자가 값을 넣을 때 사용

   buffer[fill_ptr] = value;

   fill_ptr=(fill_ptr+1)%MAX;

   count++;

}

 

int get(){ //소비자가 값을 얻을 때 사용

   int tmp=buffer[use_ptr];

   use_ptr=(use_ptr+1)%MAX;

   count--;

   return tmp;

}

 

pthread_cond_t empty, fill; //empty, fill 큐를 만든다. 큐가 하나라면 

pthread_mutex_t mutex; //값을 사용할 때 접근을 막기 위한 뮤텍스

 

void *producer(void *arg){

   int i;

   for(i=0; i<loops; i++){

      pthread_mutex_lock(&mutex); //다른 쓰레드에서 접근 못하게 뮤텍스 락을 건다

      while(count ==MAX) //버퍼가 꽉 차면

         pthread_cond_wait(&empty,&mutex); /*소비자로부터 empty큐에 뭐가 있다면(버퍼가 비었다면) 버퍼에 값을 넣기 위해 mutex lock을 푼다. */

      put(i); //버퍼에 생산한 값 넣기

      pthread_cond_signal(&fill); //버퍼에 값을 넣었으므로 fill 큐에 신호 전달해서 소비자가 값을 소비하게 해준다.

      pthread_mutex_unlock(&mutex); //뮤텍스 락을 푼다.

   }

}

 

void *consumer(void *arg){

   int i;

   for(i=0;i<loops;i++){

      pthread_mutex_lock(&mutex);

      while(count==0) //버퍼가 비면

         pthread_cond_wait(&fill,&mutex); //생산자가 버퍼에 값을 넣었다는 신호가 올 때까지 기다린다.

      int tmp = get(); //버퍼에 값이 생겼으므로 소비자는 값을 얻는다.

      pthread_cond_signal(&empty); //empty에 신호를 발생시킨다. 생산자는 값을 버퍼에 넣게 된다.

      pthread_mutex_unlock(&mutex);

      printf("%d\n",tmp);

   }

}

 

int main(int argc, char *argv[]){

   pthread_t p1,p2;

   printf("main : begin producer and consumer\n");

   pthread_create(&p1,NULL,producer,"producer"); //생산자 쓰레드 생성

   pthread_create(&p2,NULL,consumer,"consumer"); //소비자 쓰레드 생성

 

   //join wait

   pthread_join(p1, NULL); //해당 쓰레드의 종료를 기다리는 것이 pthread_join()이 하는 일

   pthread_join(p2, NULL); /*만약 join이 없다면 main함수가 끝남(프로세스 종료)과 동시에 모든 쓰레드는 종료된다. 프로그램이 실행되면 프로그램은 프로세스에서 돌아가고 프로세스 안에는 여러 쓰레드가 있다. 그러므로 main 종료 -> 생성자, 소비자 쓰레드 종료*/

   printf("main:procon done\n");

   return 0;

}
