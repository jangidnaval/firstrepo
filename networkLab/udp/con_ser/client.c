#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
#define IP "127.0.0.1"
int main(){

int sockid;
struct sockaddr_in servaddr,cliaddr;

sockid=socket(AF_INET,SOCK_DGRAM,0);

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(4000);
servaddr.sin_addr.s_addr=inet_addr(IP);

char msg[100];

int n=6;

while(1){

scanf("%s",msg);

int count=sendto(sockid,msg,sizeof(msg),0,(struct sockaddr*) &servaddr,sizeof(servaddr));


	int len=sizeof(cliaddr);
count=recvfrom(sockid,msg,sizeof(msg),0,(struct sockaddr *)&cliaddr,&len);        //used "'&""        in while recv.....   //new socket.....

printf("%s\n",msg);

}
}