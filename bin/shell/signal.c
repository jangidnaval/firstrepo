//Name Shantanu Tiwari
//REG No 20144115
#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<sys/types.h>

void handler(int sig){
    int status;
    signal(sig,SIG_IGN);
    wait(&status);
    if(sig==17){
        printf("Child process terminated with exit status:%d\n",WEXITSTATUS(&status));
    }
    signal(SIGCHLD,handler);
}

int main()
{
    int n=5;
    signal(SIGCHLD,handler);
    pid_t pid;
    pid=fork();
    if(pid==0){
        while(n>0){
            printf("abcdefgh\n");
            sleep(2);
            n--;
        }
        exit(0);
    }
    else if(pid>0){
        wait(NULL);
    }
    else
        printf("Error creating the child process\n");
 return 0;
}
