#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 20

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

int priority(char symbol){
	switch(symbol){
		case '(':return 0;
		case '+':
		case '-':return 1;
			
		case '*':
		case '/':return 2;
			

		case '^':return 3;
			
	}
	return -1;
}



void infixtopostfix(STACK *S, char infix[20]){
	int i=0,j=0;
	char temp,postfix[20],checker;

	for(i=0;infix[i]!='\0';i++){
		checker=infix[i];
		if(isalnum(checker)){
			postfix[j++]=checker;	
	}		
		else{
			switch(checker){
				case '(': push(S,checker); break;
				case ')': temp=pop(S); 
						while(temp!='('){
							postfix[j++]=temp;
							temp=pop(S);
						}	
							
					  	break;	 
				case '+': 
				case '-': 
				case '*': 
				case '/': 
				case '^': //if (S->top==-1 || S->arr[S->top]=='('){
					    //push(S,checker);}
					  //else{
					    while(priority(S->arr[S->top])>=priority(checker) ){
							postfix[j++]=pop(S);
							
						}
					push(S,checker);
						
				
					//}   				
						break;				
					} 
		 
		}

}
					
		
			


		while(S->top!=-1){
			postfix[j++]=pop(S);
					
		}
		
		postfix[j]='\0';
		printf("\nPostfix expression is %s\n",postfix);	

}


int main(){

	STACK S;
	S.top=-1;
	char infix[20];
	gets(infix);
	infixtopostfix(&S,infix);
	return 0;


}