#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define MAX 10
pthread_t tidp[10],tidc[10];
int buffer[MAX];
sem_t full,empty;
pthread_mutex_t mutex;
int counter=0;
void init()
{
sem_init(&full,1,0);
sem_init(&empty,1,MAX);
pthread_mutex_init(&mutex,0);
counter=0;
}
void write(int item)
{
buffer[counter++]=item;
}
int read()
{
return(buffer[--counter]);
}
void *producer()
{
int item,i;
item=rand()%5;
sem_wait(&empty);
pthread_mutex_lock(&mutex);
printf("\nthe item produced by producer is %d",item);
write(item);
pthread_mutex_unlock(&mutex);
sem_post(&full);
}
void *consumer()
{
int item,i;
sem_wait(&full);
pthread_mutex_lock(&mutex);
item=read();
printf("\nitem consumed is %d",item);
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}
int main()
{
int n1,n2,i;
init();
printf("producer\n");
scanf("%d",&n1);
printf("consumere\n");
scanf("%d",&n2);
for(i=0;i<n1;i++)
pthread_create(&tidp[i],NULL,producer,NULL);
for(i=0;i<n2;i++)
pthread_create(&tidc[i],NULL,consumer,NULL);
for(i=0;i<n1;i++)
pthread_join(tidp[i],NULL);
for(i=0;i<n2;i++)
pthread_join(tidc[i],NULL);
exit(0);
}


