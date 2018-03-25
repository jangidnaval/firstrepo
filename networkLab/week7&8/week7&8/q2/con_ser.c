
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <pthread.h>
#define MAXLINE 1024
#define MAXPENDING 6

void client_handler(int clientSock);
void reverse(char st[]);
void*  threadMain(void *arg);

struct threadArgs
{
     int clntSock;
};

int main(int argc,char *argv[])
{
int sockfd,clntSock,tid;
int n;
struct threadArgs *targs;
int port= atoi(argv[1]);
socklen_t len;
char msg[1024];
struct sockaddr_in servaddr,cliaddr;

sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
bzero(&servaddr,sizeof(servaddr));

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(port);


printf("\n\n Binded");
bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
printf("\n\n Listening...");

if (listen(sockfd, MAXPENDING) < 0)
	printf("\nlisten() error\n");

for(;;)
{
      printf("\n ");
     len=sizeof(cliaddr);
     
     if ((clntSock = accept(sockfd, (struct sockaddr *) &cliaddr,&len)) < 0)
     	printf("\nListening Error\n");
     printf("client connected");
    
     targs=(struct threadArgs *) malloc(sizeof(struct threadArgs));
     targs->clntSock=clntSock;
     
     if(pthread_create(&tid,NULL,threadMain,(void *)targs)!=0)
     {
          printf("pthread_create() error\n");
          exit(1);
     }
     printf("\nClient handled by  thread %ld\n", (long int) tid);
}
return 0;
}

void * threadMain(void * arg)
{
     int clntSock;
     pthread_detach(pthread_self());
     
     clntSock=((struct threadArgs * )arg)->clntSock;
     free(arg);
     client_handler(clntSock);
}

void client_handler(int clientSock)
{
	 char msg[1024];
	 int n;
	 n=recv(clientSock,msg,MAXLINE,0);
	 printf("\nRECEIVED : %s\n",msg);
	 while(n>0)
	 {
	 		reverse(msg);
	 		printf("\nSENDING: %s\n",msg);
	 		send(clientSock,msg,MAXLINE,0);
	 		strcpy(msg,"");
	 		
	 	  n=recv(clientSock,msg,MAXLINE,0);
	 }
	 close(clientSock);
}

void reverse(char st[])
{
		int i,l=strlen(st);
		char ch;
		for(i=0;i<l/2;i++)
		{
			ch=st[i];
			st[i]=st[l-i-1];
			st[l-i-1]=ch;
		}
}


