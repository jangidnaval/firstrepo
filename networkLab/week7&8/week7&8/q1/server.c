
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#define MAXLINE 1024
#define MAXPENDING 6

void client_handler(int clientSock);
void reverse(char st[]);


int main(int argc,char *argv[])
{
int sockfd,clntSock,pid,childProcCount=0;
int n;
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
    
     if((pid=fork())<0)
     {
          printf("fork() error\n");
          exit(1);
     }    
     
     if(pid==0)
     {
         close(sockfd); 
         client_handler(clntSock);
         exit(0);
     }
    
    // client_handler(clntSock);
     printf("\nclient handled by child process = %d\n",pid);
     close(clntSock);
     childProcCount++;
     while(childProcCount)
     {
          pid=waitpid((pid_t) -1,NULL,WNOHANG);
          if(pid<0)
          {
               printf("waitpid() failed\n");
               exit(1);
          }
          if(pid==0)
               break;
          else
               childProcCount--;
     }
   
   
}
return 0;
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


