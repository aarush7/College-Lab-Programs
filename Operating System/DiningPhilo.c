#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define N 5
#define LEFT (phnum+4)%N
#define RIGHT (phnum+1)%N
int state[N];
int phil[N]={0,1,2,3,4};
sem_t mutex;
sem_t s[N];
void test(int phnum)
{
if(state[phnum]==HUNGRY&&state[LEFT]!=EATING&&state[RIGHT]!=EATING)
{
state[phnum]=EATING;
sleep(2);
printf("%d philo is taking %d and %d fork\n",phnum+1,LEFT+1,phnum+1);
printf("%d is eating",phnum+1);
sem_post(&s[phnum]);
}
}
void take_fork(int phnum)
{
sem_wait(&mutex);
state[phnum]=HUNGRY;
printf("%d philo is hungry\n",phnum+1);
test(phnum);
sem_post(&mutex);
sem_wait(&s[phnum]);
sleep(1);
}
void put_fork(int phnum)
{
sem_wait(&mutex);
state[phnum]=THINKING;
printf("philo %d is putting fork %d and %d \n",phnum+1,LEFT+1,phnum+1);
printf("philo %d is thinking\n",phnum+1);
test(LEFT);
test(RIGHT);
sem_post(&mutex);
}
void *philo(void *num)
{
while(1)
{
int *i=num;
sleep(1);
take_fork(*i);
sleep(0);
put_fork(*i);
}
}
int main()
{
int i;
pthread_t thread_id[N];
sem_init(&mutex,0,1);
for(i=0;i<N;i++)
sem_init(&s[i],0,0);
for(i=0;i<N;i++)
{
pthread_create(&thread_id[i],NULL,philo,&phil[i]);
printf("\nphilo %d is thinking\n",i+1);
}
for(i=0;i<N;i++)
{
pthread_join(thread_id[i],NULL);
}
return 0;
}

