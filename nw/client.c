#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#define IP "127.0.0.1"

int main(){

struct sockaddr_in echoclientaddr;

int clientid=socket(AF_INET,SOCK_DGRAM,0);

echoclientaddr.sin_family=AF_INET;
echoclientaddr.sin_port=htons(4020);
echoclientaddr.sin_addr.s_addr=inet_addr(IP);

/*
int x=bind(clientid,(struct sockaddr *)&echoclientaddr,sizeof(echoclientaddr));
if(x<0)
printf("Error in binding\n");
else
printf("binded\n");
*/

char buffer[100];
while(1)
{
scanf("%s",buffer);

int len=sizeof(echoclientaddr);

int n=sendto(clientid,buffer,sizeof(buffer),0,(struct sockaddr*)&echoclientaddr,len);

if(n==-1)
printf("Error in sending to server \n");
else
printf("sended to server :)\n");

n=recvfrom(clientid,buffer,sizeof(buffer),0,(struct sockaddr*)&echoclientaddr,&len);

if(n==-1)
printf("Error in receing from server\n");
else
printf("Message of server is------>  %s\n",buffer);

}


}

