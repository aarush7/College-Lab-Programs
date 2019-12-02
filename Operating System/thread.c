#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<pthread.h>
#include<ctype.h>

pthread_t p1,p2;
void *fact(void *arg)
{
int i,fact=1;
for(i=atoi(arg);i>0;i--)
{fact=fact*i;
}
printf("\n%d\n",fact);
return NULL;
}
void *fre(void *arg)
{
if(isalpha(*arg))
{printf("alpha");
}
else printf("not");
}
int main(int argc,char *argv[])
{
pthread_create(&p1,NULL,fact,argv[1]);
pthread_create(&p2,NULL,fre,argv[2]);
pthread_join(p1,NULL);
pthread_join(p2,NULL);
return 0;
}
