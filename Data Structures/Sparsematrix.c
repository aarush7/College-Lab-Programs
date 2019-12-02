#include<stdio.h>
#include<stdlib.h>

struct node{
	int info,row,col;
	struct node *prev;
	struct node *next;
};
typedef struct node * nodeptr;

nodeptr getnode(){
	nodeptr newnode;
	newnode=(nodeptr)malloc(sizeof(struct node));
	return newnode;
}

nodeptr insertend(nodeptr start, int value, int row, int col){
	nodeptr temp,cur;
	temp=getnode();
	temp->info=value;
	temp->row=row;
	temp->col=col;
	temp->prev=NULL;
	temp->next=NULL;
	if(start==NULL){
		return temp;
	}
	for(cur=start;cur->next!=NULL;cur=cur->next);
	cur->next=temp;
	temp->prev=cur;
	return start;
}
void display(nodeptr start){
	nodeptr cur;
	if(start==NULL){
		printf("\nThe list is empty");
	}
	else{
		for(cur=start;cur!=NULL;cur=cur->next){
			printf("row: %d\t col: %d\t value: %d\n",cur->row,cur->col,cur->info);
		}
	}
}

void mat_display(nodeptr start,int m, int n){
	nodeptr temp;
	temp=getnode();
	int i,j;
	temp=start;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(temp!=NULL&&temp->row==i&&temp->col==j){
				printf("%d ",temp->info);
				temp=temp->next;
			}
			else{
				printf("0 ");

			}
		}
	printf("\n");
	}
}

int main(){
	nodeptr start;
	start=getnode();
	start=NULL;
	int i,j,m,n,item;
	printf("\nEnter number of rows: ");
	scanf("%d",&m);
	printf("\nEnter number of columns: ");
	scanf("%d",&n);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf(" %d",&item);
			if(item!=0){
				start=insertend(start,item,i,j);
			}
		}
	}
	display(start);
	printf("\nThe Sparse Matrix is: \n");
	mat_display(start,m,n);
	return 0;
}