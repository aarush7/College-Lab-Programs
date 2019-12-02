#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 5
void insert(int);
void display();
void delete(int);
int htable[TABLE_SIZE]={NULL};
int main()
{
int opt,i,val;
for(i=0;i<TABLE_SIZE;i++)
htable[i]=-1;
while(1)
{
printf("\nPress 1. Insert\t 2. Display \t3. Delete \t 4. exit \n");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("\nenter a value to insert into hash table\n");
scanf("%d",&val);
insert(val);
break;
case 2: display();
break;
case 3: printf("\nenter a value to delete in hash table\n");
scanf("%d",&val);
delete(val);
break;
case 4: exit(0);
}
}
}
void delete(int val)
{
int index,i,flag=0;
for(i=0;i<TABLE_SIZE; i++)
{
index=(val+i)%TABLE_SIZE;
if(htable[index]==val)
{
htable[index] = -1;
printf("value is found at index %d",index);
flag=1;
break;
}
}
if(flag==0)
printf("\n value is not found\n");
}
void display()
{
int i;
printf("\nelements in the hash table are \n");
for(i=0;i< TABLE_SIZE; i++)
printf("\nat index %d \t value = %d",i,htable[i]);
}
void insert(int val)
{
int index,i,flag=0;
for(i=0;i<TABLE_SIZE;i++)
{

index=(val+i)%TABLE_SIZE;
if(htable[index] == -1)
{
htable[index]=val;
flag=1;
break;
}
}
if(flag == 0)
printf("\nelement cannot be inserted\n");
}