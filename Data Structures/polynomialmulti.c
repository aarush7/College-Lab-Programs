#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
};
struct node* addNode(int data, struct node *first){
  struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  if(first==NULL){
  first=temp;
  first->next=NULL;
}
  else{
    temp->next=first;
    first=temp;
  }
  return first;
}
struct node* multiply(struct node *first1,struct node *first2, int order1, int order2){
  struct node *first=NULL, *first11, *first22;
  first11=first1;
  first22=first2;
  struct node *temp;
  int k,j,i;
  for(k=0;k<order1+order2+1;k++){
    temp=(struct node*)malloc(sizeof(struct node));
    if(first==NULL){
      first=temp;
      first->next=NULL;
    }
      else{
        temp->next=first;
        first=temp;
      }
      first->data=0;
    for(i=0;i<=order1;i++){
    for(j=0;j<=order2;j++){
      if(k==j+i){
        first->data+=first1->data*first2->data;
        }
        first2=first2->next;
      }
      first2=first22;
      first1=first1->next;
    }
    first1=first11;
	first2=first22;
  }
  return first;
}

int print(struct node *first){
  printf("%d\n", first->data);
  if(first->next==NULL){
  return 0;
}
  else{
      return(print(first->next));
    }
	}

    int main() {
      int order1, order2;
      struct node *first1=NULL, *first2=NULL, *final;
		int i;
		int data;
		printf("polynomial 1: enter degree\n");
      scanf("%d", &order1);
      printf("enter coeffs(lowest power to highest)\n");
      for(i=0;i<=order1;i++){
      scanf("%d", &data);
      first1=addNode(data,first1);
    }
    printf("polynomial 2: enter degree\n");
    scanf("%d", &order2);
    printf("enter coeffs(lowest power to highest)\n");
    for(i=0;i<=order2;i++){
    scanf("%d", &data);
    first2=addNode(data,first2);
  }
  printf("final ans:\n");
  final=multiply(first1, first2, order1, order2);
  print(final);
      return 0;
    }