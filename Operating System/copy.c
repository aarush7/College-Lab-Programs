#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>

int main(int arg,char *argv[])
{

int fd1,fd2,n;
char buf[20];
fd1=open(argv[1],O_RDONLY);
fd2=open(argv[2],O_WRONLY);
if(fd1==-1)
{
printf("cannot open file");
}
else{
while((n=read(fd1,buf,20))!=0)
{
write(fd2,buf,n);
}
printf("File Copying succcessful");
}
close(fd1);
close(fd2);
}

