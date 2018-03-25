#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(char *arg[])
{
	execl("/bin/grep","rajeev","a.txt",NULL);
}
