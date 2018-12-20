#include<stdio.h> 
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>
#include<sys/ipc.h>
#include<errno.h>
#include<sys/shm.h>
#include<time.h>
#define PERM S_IRUSR|S_IWUSR
#define PORT 4567
#define BACKLOG 10
#define WELCOME "You are now connected to the server. Welcome."

//convert int type char
void itoa(int i,char*string)

{

  int power,j;

  j=i;

  for(power=1;j>=10;j/=10)

    power*=10;

  for(;power>0;power/=10)

    {

     *string++='0'+i/power;

      i%=power;

    }

  *string='\0';

}

 

//get current system time

void get_cur_time(char * time_str)

{

  time_t timep;

  struct tm *p_curtime;

  char *time_tmp;

  time_tmp=(char *)malloc(2);

  memset(time_tmp,0,2);

  memset(time_str,0,20);

  time(&timep);

  p_curtime = localtime(&timep);

  strcat(time_str," (");

  itoa(p_curtime->tm_hour,time_tmp);

  strcat(time_str,time_tmp);

  strcat(time_str,":");

  itoa(p_curtime->tm_min,time_tmp);

  strcat(time_str,time_tmp);

  strcat(time_str,":");

  itoa(p_curtime->tm_sec,time_tmp);

  strcat(time_str,time_tmp);

  strcat(time_str,")");

  free(time_tmp);

}

//create shared memory area

key_t shm_create()

{

  key_t shmid;

 if((shmid = shmget(IPC_PRIVATE,1024,PERM)) == -1)

   {

     fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno));

     exit(1);

   }

  return shmid;

}

//creates a socket and bind to the port specified

int bindPort(unsigned short int port)

{

  int sockfd;

  struct sockaddr_in my_addr;

  sockfd = socket(AF_INET,SOCK_STREAM,0);

  my_addr.sin_family = AF_INET;

  my_addr.sin_port = htons(port);

  my_addr.sin_addr.s_addr = INADDR_ANY;

  bzero(&(my_addr.sin_zero),0);

   

  if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr)) == -1)

    {

      perror("bind");

      exit(1);

    }

  printf("Success!\n");

  return sockfd;

}

int main(int argc, char *argv[])

{

  int sockfd,clientfd,sin_size,recvbytes; //listening socket and the client socket

  pid_t pid,ppid;  //parent child

  char *buf, *r_addr, *w_addr, *temp, *time_str;//temp storage

  struct sockaddr_in their_addr;  //address

  key_t shmid;

   

  shmid = shm_create(); //creating shared memory area using function

   

  temp = (char *)malloc(255);

  time_str=(char *)malloc(20);

   sockfd = bindPort(PORT);//绑定端口

   while(1)
   {   

     if(listen(sockfd,BACKLOG) == -1)//在指定端口上监听

     {

       perror("listen");

       exit(1);

     }

     printf("Listening......\n");

     if((clientfd = accept(sockfd,(struct sockaddr*)&their_addr,&sin_size)) == -1)

     {

      perror("accept");

      exit(1);

    }

      printf("accept from:%d\n",inet_ntoa(their_addr.sin_addr));

     send(clientfd,WELCOME,strlen(WELCOME),0);//send the welcome message

     buf = (char *)malloc(255);

      

     ppid = fork();//creating child process

     if(ppid == 0)

       {

     pid = fork();  //creating child process 

     while(1)

       {

         if(pid > 0)

           {

         //parent process for receiving information

         memset(buf,0,255);

         if((recvbytes = recv(clientfd,buf,255,0)) <= 0)

           {

             perror("recv1");

             close(clientfd);

             raise(SIGKILL);

             exit(1);

           }

         //write buf's data to share memory

         w_addr = shmat(shmid, 0, 0);

         memset(w_addr, '\0', 1024);

         strncpy(w_addr, buf, 1024);

         get_cur_time(time_str);

         strcat(buf,time_str);

         //here is where the server prints what it got from the client

         printf(" %s\n",buf);

           }

         else if(pid == 0)

           {

         //child is used to send information

         sleep(1);

         r_addr = shmat(shmid, 0, 0);

         if(strcmp(temp,r_addr) != 0)

           {

             strcpy(temp,r_addr);

             get_cur_time(time_str);          

             strcat(r_addr,time_str);

             if(send(clientfd,r_addr,strlen(r_addr),0) == -1)

               {

             perror("send");

               }

             memset(r_addr, '\0', 1024);

             strcpy(r_addr,temp);

           }

           }

         else

          perror("fork");

       }

       }

    }

  free(buf);

  close(sockfd);

  close(clientfd);

  return 0;

}

