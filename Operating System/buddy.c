#include<stdio.h>
#include<stdlib.h>
#define FREE 0
#define OCC 1
#define SPLIT 2
struct tree{
  char data;
  int size;
  struct tree *right, *left;
  int status;
};
typedef struct tree node;

node* addnodes(node *head){
  node *temp1, *temp2;
  temp1=(node*)malloc(sizeof(node));
  temp2=(node*)malloc(sizeof(node));
  temp1->size=head->size/2;
  temp2->size=head->size/2;
  temp1->left=NULL;
  temp1->right=NULL;
  temp2->left=NULL;
  temp2->right=NULL;
  temp1->status=FREE;
  temp2->status=FREE;
  head->status=SPLIT;
  head->left=temp1;
  head->right=temp2;
  printf("nodes added\n");
}

int build_tree(node *head, char data, int size){
  if(head->status==OCC){
    printf("head->status==occ\n");
  return 0;
}

  if(size>head->size){
    printf("size>head->size\n");
  return 0;
}

  else if(size>head->size/2){
    printf("size>=head->size/2\n");
    if(head->status==FREE){
      printf("size->status==FREE, putting node\n");
      head->status=OCC;
      head->data=data;
      return 1;
    }
    else
      return 0;
  }

  else if(size==head->size){
    head->status=OCC;
    head->data=data;
    return 1;
  }

  else if(size<=head->size/2){
    if(head->status==FREE){
      printf("size<head->size/2 and status==free\n");
      addnodes(head);
      return build_tree(head->left,data,size);
    }
    if(head->status==SPLIT){
      printf("size<head->size/2 and status==split\n");
      if(build_tree(head->left,data,size))
        return 1;
      return build_tree(head->right,data,size);
    }
  }
}

node* search_parent(node* head, char data){
  if(head->data==data) return head;
  if(head->left==NULL)
    return head->left;
  if(head->left->data==data||head->right->data==data)
    return head;
  node *p=search_parent(head->left,data);
  node *q=search_parent(head->right,data);
  if(p!=NULL)
    return p;
    return q;
}

void delete(node *head, char data){
  node *p;
  p=search_parent(head, data);
  if(p==NULL){
    printf("element not found\n");
    return;
  }
  else if(p->status==OCC)
  p->status=FREE;
  else{
  if(p->left->data==data)
  p->left->status=FREE;
  else
  p->right->status=FREE;
  if(p->right->status==FREE&&p->left->status==FREE)
    p->status=FREE;
}
}

void display_tree (node* head)
{
	if (head->status == SPLIT)
	{
		display_tree (head->left);
		display_tree (head->right);
	}
	else{
    if(head->status==OCC)
		printf ("%c:%d:%d\t",head->data,head->size,head->status);
    if(head->status==FREE)
    printf ("%d:%d\t",head->size,head->status);
}
}
int main(){
  node *head, *p;
  int size, ch;
  char data;
  printf("input size of memory:\n");
  scanf("%d", &size);
  head=(node*)malloc(sizeof(node));
  head->size=size;
  head->status=FREE;
  head->left=NULL;
  head->right=NULL;
  while(1){
    printf("choose:\n1. add to tree\n2. remove from tree\n3. search tree\n4. print\n");
    scanf("%d", &ch);
  switch(ch){
    case 1: printf("enter label and size of node to be added\n");
            scanf(" %c", &data);
            scanf(" %d", &size);
            if(build_tree(head,data,size))
            printf("element added\n");
            else
            printf("space unavailable\n");
            break;
    case 2: printf("enter data to remove:\n");
            scanf(" %c", &data);
            delete(head,data);
            break;
    case 3: printf("enter data to search:\n");
            scanf(" %c", &data);
            p=search_parent(head,data);
            if(p==NULL)
            printf("element not found\n");
            else{
              if(p->right->data==data)
              p=p->right;
              else
              p=p->left;
              }
            printf("data found: %c:%d:%d", p->data,p->size,p->status);
            break;
    case 4: display_tree(head);
            break;
    default: exit(0);
  }
}
}
