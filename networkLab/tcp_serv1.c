#
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include <string.h>

int main(){
  int welcomeSocket, newSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;


  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  

  serverAddr.sin_family = AF_INET;
 
  serverAddr.sin_port = htons(7891);

  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  

  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));


  if(listen(welcomeSocket,5)==0)
    printf("Listening\n");
  else
    printf("Error\n");


  addr_size = sizeof serverStorage;
  newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);

  
   recv(newSocket, buffer, 1024, 0);
   printf("Message recieved : - %s\n",buffer);
   int l=strlen(buffer);
   int i=0;
   char temp;
   l=l-1;
   while(i<l)
   {
   		temp=buffer[i];
   		buffer[i]=buffer[l];
   		buffer[l]=temp;
   		i++;
   		l--;
   
   }
 
  
  send(newSocket,buffer,sizeof(buffer),0);


  return 0;
}
