#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
 
#define BUF_SIZE 100
#define NAME_SIZE 20
 
void error_handling(char *message);
void read_routine(int sock, char *buf);
void write_routine(int sock, char *buf);
 
char name[NAME_SIZE] = "[NULL]";
char buf[BUF_SIZE];
 
int main(int argc, char *argv[]) {
    //소켓, pid값 등을 저장할 변수선언
    int sock;
    pid_t pid;
    char buf[BUF_SIZE];
    struct sockaddr_in serv_adr;
    
    //입력 포맷이 맞지 않으면 오류 출력 후 종료
    if(argc!=4) {    
        printf("Usage : %s <IP> <port> <name>\n", argv[0]);
        exit(1);
    }
    //데이터를 형식에 맞추어 쓰드록 지정
    sprintf(name, "[%s]", argv[3]);
 
    //클라이언트 소켓 설정
    sock=socket(PF_INET, SOCK_STREAM, 0);  
    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family=AF_INET;
    serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_adr.sin_port=htons(atoi(argv[2]));
    
    //connect함수를 통해 서버와 연결 시도
    if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
        error_handling("connect() error!");
 
    //fork 함수를 통해 입력, 출력을 처리하는 프로세스를 각각 만듦 
    pid=fork();
    if(pid==0)
        write_routine(sock, buf);
    else 
        read_routine(sock, buf);
 
    close(sock);
    return 0;
}
 
//서버로부터 메세지를 읽어들이는 함수
void read_routine(int sock, char *buf) {
    char total_msg[NAME_SIZE + BUF_SIZE];
    while(1) {
        //서버로부터 메세지를 읽어들임
        int str_len=read(sock, total_msg, NAME_SIZE + BUF_SIZE);
        
        //close를 받았다면 종료
        if(str_len==0)
            return;
 
        //데이터 출력
        total_msg[str_len]=0;
        fputs(total_msg, stdout);
        //printf("Message from server: %s", buf);
    }
}
 
//서버로 메세지를 전송하는 함수
void write_routine(int sock, char *buf) {
    char total_msg[NAME_SIZE + BUF_SIZE];
    while(1) {
        //입력값을 받아들임
        fgets(buf, BUF_SIZE, stdin);
        
        //만약 'q'나 'Q' 문자가 입력되면 종료 
        if(!strcmp(buf,"q\n") || !strcmp(buf,"Q\n")) {    
            shutdown(sock, SHUT_WR);
            return;
        }
        
        //데이터를 형식에 맞추어 쓰드록 지정
        sprintf(total_msg, "%s %s", name, buf);
        
        //서버로 입력한 데이터 전송
        write(sock, total_msg, strlen(total_msg));
    }
}
 
void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}



