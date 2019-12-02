#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

struct stack {

	int top;
	int arr[SIZE]; 
};

typedef struct stack STACK;

int push(STACK *S, int element){

	if((S->top)==(SIZE-1)){
		return -1;}
	else{
		
		S->top+=1;
		S->arr[S->top]=element;			
		return 0;	
	}

}

int pop(STACK *S){
	int del;
	if(S->top==-1)
		return -1;
	else{
		del=S->arr[S->top];
		S->top-=1;
		return del;
	}
}

void display(STACK S){
	int i=0,j=0;
	if(S.top<=-1){
		printf("\nStack empty\n");
	}
	else{
		for(i=S.top;i>=0;i--){
			printf("\nElement %d: %d",j+1,S.arr[i]);
			j++;		
		}	
	}	
	

}



int get_top3rd(STACK *S){
	STACK S1;
	S1.top=-1;
	int var,init,final;
	int i,j=0;
	init=S->top;
	final=S->top-3;
	if(final>=-1){
	for (i=init;i>final;i--){
		var=pop(S);	
		push(&S1,var);	

	}
	
	while(S1.top!=-1){
		push(S,pop(&S1));
	}	
	return var;}

	else{
		printf("\nNo top 3rd element\n");
		return -2;}
}

int get_bottom3rd(STACK *S){
	STACK S1;
	S1.top=-1;
	int var,init,final;
	int i,j=0;
	init=S->top;
	final=S->top-3;
	if (final>=-1){	
	for (i=0;i<=init;i++){	
		push(&S1,pop(S));	

	}
	var=S1.arr[S1.top-2];
	while(S1.top!=-1){
		push(S,pop(&S1));
	}	
	return var;}

	else{
		printf("\nNo bottom 3rd element\n");
		return -2;
	}			
}

void popn(STACK *S,int n){
	int i,arr[1000];	
	if(n<=S->top+1){	
	for(i=0;i<n;i++){
		arr[i]=pop(S);
	}
	for(i=0;i<n;i++){
		printf("%d,",arr[i]);	
	}
	printf(" have been poped\n");
	}
	else
		printf("\n Unable to pop\n");
}


int main(){
	int ch,var,var1,element,Y,n;
	STACK S;
	S.top=-1;	
	while(1){
	printf("\n1:Push\n2:Pop\n3:Display\n4:Display third element from top of the stack\n5:Display third element from bottom of the stack\n6:Pop n number of elements\n7:Exit\nEnter your choice: ");
	scanf("%d",&ch);	
	switch(ch){

	case 1: printf("\nEnter a elemnent to push: "); 
    scanf("%d",&element); 
    var1 = push(&S,element); 
    if(var1==0)
    { break;} 
    else 
    {
        printf("\nStack Overflow\n"); 
        break;
        }
	case 2: var=pop(&S);
		if (var==-1)
			printf("\nNothing to pop\n");
		else			
		printf("\nThe element %d has been popped\n",var); 
        break;
	case 3: printf("\nElements in the stack are :\n"); 
    display(S); 
    break;
	case 4: Y=get_top3rd(&S); 
    if(Y!=-2) 
    {
        printf("\nThird element from top is: %d\n",Y);
        break;
        	} 
        else 
        break;
	case 5: Y=get_bottom3rd(&S); 
    if(Y!=-2) 
    {
        printf("\nThird element from bottom is: %d\n",Y);
        break;	
        } 
        else
         break;	
	case 6: printf("\nEnter number of elements to pop: "); 
    scanf("%d",&n); 
    popn(&S,n); 
    break;
	default: 
    exit(0); 
	
}

}


return 0;
}