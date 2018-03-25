#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<netdb.h>
#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#define IP "127.0.0.1"

void fun(char msg[]){



}

int main(){

int sockid;
struct sockaddr_in servaddr,cliaddr;

sockid=socket(AF_INET,SOCK_DGRAM,0);

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(4000);
servaddr.sin_addr.s_addr=inet_addr(IP);

int k=bind(sockid,(struct sockaddr *) &servaddr,sizeof(servaddr));

if(k!=-1)
printf("Binded successfully\n");
	char msg[100];
int n=6;
int fd=fork();
if(fd!=0)
{
while(1)
{

int len=sizeof(cliaddr);
int count=recvfrom(sockid,msg,sizeof(msg),0,(struct sockaddr *)&cliaddr,&len);

//fun(msg);
sendto(sockid,msg,sizeof(msg),0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
}
}
}


