#include<stdio.h>

int main()
{
while(1)
{
char a[20];
char buf[1000];
printf("myShell$ ");
scanf("%s",a);

if(strcmp(a,"pwd")==0)
{
getcwd(buf,1000);
printf("%s\n",buf);
}
else if(strcmp(a,"ls")==0)
{
system("ls");
}
else if(strcmp(a,"cd_dir")==0)
{
scanf("%s",buf);
chdir(buf);
}
else if(strcmp(a,"mk_dir")==0)
{
scanf("%s",buf);
mkdir(buf);
}
else if(strcmp(a,"rm_dir")==0)
{
scanf("%s",buf);
rmdir(buf);
}

else if(strcmp(a,"exit")==0)
{
break;
}
else
    system(a);


}
}

