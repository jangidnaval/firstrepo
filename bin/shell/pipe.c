//NAME SHANTANU TIWARI
//REG NO 20144115
//Using pipe() system call to send a string of characters from parent process to child
//process. Child process will read the string and print the string in child process itself.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int fd[2],pid;
char line[100],str[100];
gets(str);
if(pipe(fd)<0)
{
printf("error\n");
exit(0);
}
if((pid=fork())<0)
{
printf("error");
exit(0);
}
else if(pid>0)
{
close(fd[0]);
write(fd[1],str,strlen(str)+1);
close(fd[1]);
//dup(fd[1]);
}
else
{
close(fd[1]);
int n=read(fd[0],line,100);
write(1,line,strlen(str)+1);
//printf("%s\n",line);
//printf("\n%d",n);
}
return 0;
}
