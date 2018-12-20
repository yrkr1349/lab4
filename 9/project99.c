#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<netdb.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>

int main(int argc, char *argv[]) {
  struct sockaddr_in clientaddress;//address
  pid_t pid;
  int clientfd,sendbytes,recvbytes;//client socket
  struct hostent *host;
  char *buf,*buf_r;
  if(argc < 4) {
      printf("Format:\n");
      printf("%s [IP ADDRESS] [PORT] [NICKNAME]\n",argv[0]);
      exit(1);
    }

  host = gethostbyname(argv[1]);
  if((clientfd = socket(AF_INET,SOCK_STREAM,0)) == -1)  //creating client socket
  {
      perror("socket\n");
      exit(1);

    }

  //binding client socket

  clientaddress.sin_family = AF_INET;
  clientaddress.sin_port = htons((uint16_t)atoi(argv[2]));
  clientaddress.sin_addr = *((struct in_addr *)host->h_addr);
  bzero(&(clientaddress.sin_zero),0);
  if(connect(clientfd,(struct sockaddr *)&clientaddress,sizeof(struct sockaddr)) == -1) //connect server
    {
      perror("connect\n");
      exit(1);
    }

  buf=(char *)malloc(120);
  memset(buf,0,120);
  buf_r=(char *)malloc(100);   

  if( recv(clientfd,buf,100,0) == -1) {
      perror("recv:");
      exit(1);
    }

  printf("\n%s\n",buf);
  pid = fork();//create child process

  while(1) {
      if(pid > 0){
    //parent process used to send information
    	strcpy(buf,argv[3]);
    	strcat(buf,":");
    	memset(buf_r,0,100);

    fgets(buf_r,100,stdin);

    strncat(buf,buf_r,strlen(buf_r)-1);

    //this is where the client sends the message to the server

    if((sendbytes = send(clientfd,buf,strlen(buf),0)) == -1)

      {

        perror("send\n");

       exit(1);

      }

      }

      else if(pid == 0)

    {

      //child process used to receive information

      memset(buf,0,100);

      if(recv(clientfd,buf,100,0) <= 0)

        {

          perror("recv:");

          close(clientfd);

          raise(SIGSTOP);

          exit(1);

        }

      //here is where the client prints what it got from the server

      printf("%s\n",buf);

    }

      else

    perror("fork");

    }

  close(clientfd);

  free(buf_r);

  free(buf);

  buf=NULL;

  buf_r=NULL;

  return 0;  

}

