
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAXLINE 1024



int main(int argc,char* argv[])
{
	int sockfd;
	int n;
	int port=atoi(argv[2]);
	socklen_t len;
	char sendto[1024],receive[1024];
	
	struct sockaddr_in servaddr;
	
	strcpy(sendto,"");
	printf("\n Enter the message : ");
	scanf("%s",sendto);
	
	sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(port);
	
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	
	len=sizeof(servaddr);
	send(sockfd,sendto,MAXLINE,0);
	
	n=recv(sockfd,receive,MAXLINE,0);
	printf("\n Server's Echo : %s\n\n",receive);
	return 0;
}
