#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ll{
  int data;
  struct ll* next;
};
typedef struct ll node;

node* addnode(node* no, int data){
  node *temp;
  temp=(node*)malloc(sizeof(node));
  temp->data=data;
  if(no==NULL){
    no=temp;
    no->next=no;
  }
  else{
    temp->next=no->next;
    no->next=temp;
  }
  return no;
}

node* add(node* no1, node* no2){
  node *temp=NULL, *init=no1->next;
  int sum=0, carry=0;
  no1=no1->next;
  no2=no2->next;
  do{
    sum=no1->data+no2->data;
    temp=addnode(temp, (sum+carry)%10);
    carry=(sum>=10||carry==1&&sum==9?1:0);
    no1=no1->next;
    no2=no2->next;
  }while(no1!=init);
  if(carry==1)
  addnode(temp,1);
  return temp;
}

node* zeros(node *no, int n){
  int i;
  node *temp, *a=no->next;
  for(i=0;i<n;i++){
  temp=(node*)malloc(sizeof(node));
  temp->data=0;
  no->next=temp;
  no=temp;
  }
  no->next=a;
  return no;
}

void print(node* no){
    node *init;
    no=no->next;
    init=no;
    do{
      printf("%d", no->data);
      no=no->next;
    }while(no!=init);
    printf("\n");
}

int main(){
  int i, n1, n2;
  node *no1=NULL, *no2=NULL, *no3;
  char str[10], str2[10];

  printf("enter first no\n");
  scanf("%s", str);
  n1=strlen(str);
  for(i=0;i<n1;i++)
    no1=addnode(no1, str[i]-48);

  printf("enter second no\n");
  scanf("%s", str2);
  n2=strlen(str2);
  for(i=0;i<n2;i++)
    no2=addnode(no2, str2[i]-48);
    
  if(n1>n2)
    no2=zeros(no2, n1-n2);
    else
    no1=zeros(no1, n2-n1);
  no3=add(no1,no2);
  printf("sum=");
  print(no3);
}
