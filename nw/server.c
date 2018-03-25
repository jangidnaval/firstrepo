#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define IP "127.0.0.1"

int main()
{
struct sockaddr_in echoserveraddr;

int serverid=socket(AF_INET,SOCK_DGRAM,0);

echoserveraddr.sin_family=AF_INET;
echoserveraddr.sin_port=htons(4020);
echoserveraddr.sin_addr.s_addr=inet_addr(IP);

int x=bind(serverid,(struct sockaddr *) &echoserveraddr, sizeof(echoserveraddr) );

if(x==-1)
printf("Error in binding\n");
else
printf("Binded succesfully");


char buffer[100];
printf("wating for client\n");
while(1){


int len=sizeof(echoserveraddr);
int n=recvfrom(serverid,buffer,sizeof(buffer),0,(struct sockaddr*) &echoserveraddr,&len );

if(n==-1)
	printf("Error in receiving\n");
else
printf("Message from client --> %s \n",buffer);

scanf("%s",buffer);

n=sendto(serverid,buffer,sizeof(buffer),0,(struct sockaddr *) &echoserveraddr,sizeof(echoserveraddr));

}
}
























