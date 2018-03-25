#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/types.h>
#define IP "127.0.0.1"

int main(){

struct sockaddr_in echoclientaddr;


int clientid=socket(AF_INET,SOCK_STREAM,0);

echoclientaddr.sin_family=AF_INET;
echoclientaddr.sin_port=htons(4040);
echoclientaddr.sin_addr.s_addr=inet_addr(IP);

int x=connect(clientid,(struct sockaddr *) &echoclientaddr,sizeof(echoclientaddr));
//int x=connect(clientid);
if(x==-1)
printf("Error in connecting....:(\n" );
else
printf("Connected to server\n");

char  buffer[100];

while(1){

scanf("%s",buffer);

x=send(clientid,buffer,sizeof(buffer),0);

if(x==-1)
printf("Error in sending ..:( \n");

recv(clientid,buffer,sizeof(buffer),0);
if(x==-1)
printf("Error in receiving ..:( \n");
else
printf("Message form server -----> %s",buffer);

}
}

