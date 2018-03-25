#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  addr_size = sizeof(serverAddr);
 connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
int n=5;
while(n--)
{
  recv(clientSocket, buffer, sizeof(buffer), 0);

  printf("Data received: %s",buffer);   

scanf("%s",buffer);
  send(clientSocket,buffer,sizeof(buffer),0);

 } 
  return 0;
}