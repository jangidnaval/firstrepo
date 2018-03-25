#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<time.h>
#define MAXLINE 1024
int main(int argc,char **argv){
	int sockfd;
	int n;
	socklen_t len;
	char msg[1024];
	struct sockaddr_in servaddr,cliaddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=INADDR_ANY;
	servaddr.sin_port=htons(5035);
	printf("\n\n Binded");
	bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	printf("\n\n Listening...");
	struct tm *info;
          char buffer[80];
        time_t rawtime;
         for(;;){
     		printf("\n ");
     		len=sizeof(cliaddr);
     	n=recvfrom(sockfd,msg,MAXLINE,0,(struct sockaddr*)&cliaddr,&len);
    		printf("\n Client's Message : %s\n",msg);
     		if(n<6)
        		perror("send error");
                 time( &rawtime );
              info = localtime( &rawtime );
              strftime(buffer,80,"%x - %I:%M%p", info);
     		sendto(sockfd,buffer,n,0,(struct sockaddr*)&cliaddr,len);
              printf("Server has sent time %s to client...\n",buffer);	
}
	return 0;
}
