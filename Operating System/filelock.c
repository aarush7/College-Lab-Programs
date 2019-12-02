#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main(int argc,char *argv[])
{
int fd;
char buffer[255];
struct flock fvar;
if(argc==1)
{
printf("usage: %s filename\n",argv[0]);
return -1;
}
if((fd=open(argv[1],O_RDWR))==-1)
{
perror("open");
exit(1);
}
fvar.l_type=F_WRLCK;
fvar.l_whence=SEEK_SET;
fvar.l_start=0;
fvar.l_len=100;
if((fcntl(fd,F_SETLK,&fvar))==0)
{sleep(20);
}
else
{
fcntl(fd,F_GETLK,&fvar);
printf("\nfile already locked by process (pid):  %d",fvar.l_pid);
return -1;
}
printf("press enter to release lock");
getchar();
fvar.l_type=F_UNLCK;
fvar.l_whence=SEEK_SET;
fvar.l_start=0;
fvar.l_len=100;
if((fcntl(fd,F_UNLCK,&fvar))==-1)
{
perror("fcntl");
exit(0);
}
printf("unlocked");
close(fd);
return 0;
}
