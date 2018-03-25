#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define IP "127.0.0.1"
int main(){
int serverid;
struct sockaddr_in echoserveraddr;

serverid=socket(AF_INET,SOCK_STREAM,0);

echoserveraddr.sin_family=AF_INET;
echoserveraddr.sin_port=htons(4040);
echoserveraddr.sin_addr.s_addr=inet_addr(IP);

int x=bind(serverid,(struct sockaddr*) &echoserveraddr,sizeof(echoserveraddr));

if(x==-1)
printf("Error in binding \n");
else
printf("Binded \n");

x=listen(serverid,5);
if(x==-1)
printf("Error in listening \n");
else 
printf("Listening....\n");

int len=sizeof(echoserveraddr);

int newservid=accept(serverid,(struct sockaddr *) &echoserveraddr,&len);

char buffer[100];

while(1)
{
x=recv(newservid,buffer,sizeof(buffer),0);
if(x==-1)
printf("Error in receiving \n");
else
printf("message from client -------:)     %s",buffer);

scanf("%s",buffer);
x=send(newservid,buffer,sizeof(buffer),0);

if(x==-1)
	printf("Error in sending ..:( \n ");


}

}





















