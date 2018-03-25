
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include<arpa/inet.h>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  

  serverAddr.sin_family = AF_INET;

  serverAddr.sin_port = htons(7891);

  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

 
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
  printf("Message\n");
  scanf(" %[^\n]s",buffer);
  //strcpy(buffer,"World World\n");
  
  send(clientSocket,buffer,sizeof(buffer),0);

  recv(clientSocket, buffer, 1024, 0);
	
  
  printf("Data received: %s",buffer);   

  return 0;
}
