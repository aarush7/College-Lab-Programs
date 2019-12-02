#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
sem_t mutex,wrt;
int b,count;
void *write()
{
sem_wait(&wrt);
b++;
printf("writer wrote %d.\nwriter is leaving\n",b);
sem_post(&wrt);
}
void *read(void *arg)
{int *i=(int*)arg;
sem_wait(&mutex);
count++;
if(count==1)
sem_wait(&wrt);
sem_post(&mutex);
printf("reader %d read %d\n reader %d is leaving",*i,b,*i);
sem_wait(&mutex);
count--;
if(count==0)
sem_post(&wrt);
sem_post(&mutex);
}
int main()
{
pthread_t w,r1,r2;
int rr1=1,rr2=2;
int flag=5;
sem_init(&mutex,0,1);
sem_init(&wrt,0,1);
while(flag--)
{
pthread_create(&w,NULL,write,NULL);
pthread_create(&r1,NULL,read,&rr1);
pthread_create(&r2,NULL,read,&rr2);
pthread_join(w,NULL);
pthread_join(r1,NULL);
pthread_join(r2,NULL);
}
return 0;
}



