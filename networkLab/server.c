#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<string.h>
#include<arpa/inet.h>
#include<stdio.h>
int main(){
  int sockid, newSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr,serverStorage;
 // struct sockaddr_storage serverStorage;
  socklen_t addr_size;

   sockid = socket(AF_INET, SOCK_STREAM, 0);
  
   serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sockid, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  if(listen(sockid,5)==0)
    printf("connected\n");
  else
    printf("Error\n");
      
  addr_size = sizeof(serverStorage) ;
  newSocket = accept(sockid, (struct sockaddr *) &serverStorage, &addr_size);
int n=6;
while(n--)
{
  scanf("%s",buffer);
  send(newSocket,buffer,sizeof(buffer),0);


  recv(newSocket, buffer, sizeof(buffer), 0);

  printf("Server received: %s",buffer); 
}


  return 0;
}