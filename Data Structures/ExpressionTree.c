#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


struct node{
char data;
struct node *right,*left;
};

typedef struct node*  NODE;

NODE createNode(char item){
NODE temp;
temp=(NODE) malloc(sizeof(struct node));

temp->data=item;
temp->left=NULL;
temp->right=NULL;

return temp;
}

int preced(char c){
switch(c){
case '^':return 5;
case '*':
case '/':return 3;
case '-':
case '+':return 1;
}
}

NODE createExpTree(char infix[]){
NODE treestack[20],opstack[20],temp,t,l,r;
int top1=-1,top2=-1,i;
char sym;

for(i=0;infix[i]!='\0';i++){
	sym=infix[i];
	
	if(isalnum(sym)){
		temp=createNode(sym);
		treestack[++top1]=temp;
	}

	else{
	temp=createNode(sym);
	if(top2==-1)
		opstack[++top2]=temp;

	else{
	while(preced(sym)<=preced(opstack[top2]->data) && top2!=-1){
		t=opstack[top2--];
		r=treestack[top1--];
		l=treestack[top1--];
		
		t->left=l;
		t->right=r;

		treestack[++top1]=t;
	}
	
	opstack[++top2]=temp;
	}
	}
}


while(top2!=-1){
t=opstack[top2--];
r=treestack[top1--];
l=treestack[top1--];

t->right=r;
t->left=l;

treestack[++top1]=t;
}

return treestack[top1];
}

void preorder(NODE root){

if(root!=NULL){
	printf("\t%c\t",root->data);
	preorder(root->left);
	preorder(root->right);
}

}

void inorder(NODE root){

if(root!=NULL){
	inorder(root->left);
        printf("\t%c\t",root->data);
        inorder(root->right);
}

}

void postorder(NODE root){

if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
	printf("%c\t",root->data);

}

}

void main(){
NODE root=NULL;

char infix[20];

printf("\nEnter the expression:");
scanf("%s",infix);

root=createExpTree(infix);

printf("\n Preorder traversal is:");
preorder(root);

printf("\n Inorder traversal is:");
inorder(root);

printf("\n Postorder traversal is:");
postorder(root);

printf("\n");

}

