#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 3

struct queue{
	int f,r;
	char str[SIZE][30];
};

typedef struct queue QUEUE;

void enqueue(QUEUE *CQ,char str[3]){
	if(CQ->f==(CQ->r+1)%SIZE){
		printf("\nQueue is full\n");
	}
	else{
		CQ->r=((CQ->r+1)%SIZE);
		strcpy(CQ->str[CQ->r],str);
	if(CQ->f==-1)
		CQ->f+=1;
	}
}

char *dequeue(QUEUE *CQ){
	char *del;
	if(CQ->r==-1){
		printf("\nQueue is empty");
		return NULL;
	}
	else{
		del=CQ->str[CQ->f];
		if(CQ->f==CQ->r){
			CQ->f=-1;
			CQ->r=-1;
		}
		else
			CQ->f=(CQ->f+1)%SIZE;
		return del;
	}
}

void display(QUEUE CQ){
	int i;
	if(CQ.f==-1)
		printf("\nQueue is empty\n");
	else if(CQ.r>=CQ.f){
		printf("\nMessages are:\n");
		for(i=CQ.f;i<=CQ.r;i++){
			printf("%s\n",CQ.str[i]);
		}
	}
	else {
		printf("\nMessages are:\n");
		for(i=CQ.f;i<SIZE;i++){
			printf("%s\n",CQ.str[i]);
		}
		for(i=0;i<=CQ.r;i++){
			printf("%s\n",CQ.str[i]);
		}
	}
	
}

int main(){

	QUEUE CQ;
	CQ.f=-1;
	CQ.r=-1;
	int ch;
	char *del;
	char str[3];
	while(1){
		printf("\n1:Add a message\n2:Delete a message\n3:Display messages\n4:Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter your message: "); scanf(" %[^\n]s",str); enqueue(&CQ,str); break;
			case 2:del=dequeue(&CQ); if(del!=NULL) printf("%s has been deleted",del); break;
			case 3:display(CQ); break;
			default: exit(0);
		}
	}
	return 0;
}
