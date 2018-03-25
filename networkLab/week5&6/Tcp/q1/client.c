#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#define MAXLINE 1024
int main(int argc,char* argv[]){
	int sockfd;
	int n;
	socklen_t len;
	char msg[1024],msg1[1024];
	struct sockaddr_in servaddr;
	strcpy(msg,"");
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(8080);
	
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	while(1){
printf(" Enter the message :  ");
	scanf("%s",msg);
	len=sizeof(servaddr);
	if((sendto(sockfd,msg,MAXLINE,0,(struct sockaddr*)&servaddr,len))==-1)
perror("send error");;
	n=recvfrom(sockfd,msg1,MAXLINE,0,NULL,NULL);
	msg1[n]=0;
	printf("server read: %s\n",msg1);

}	return 0;
}
