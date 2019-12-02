#include <stdio.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *left, *right;
};
typedef struct node * nodeptr;

nodeptr getnode(){
	return (nodeptr)malloc(sizeof(struct node));
}

nodeptr createbst(nodeptr root, int key){
	nodeptr temp,prev,cur;
	temp=getnode();
	cur=getnode();
	temp->info=key;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
		return temp;
	for(prev=NULL,cur=root;cur!=NULL;){
		prev=cur;
		if(key < cur->info)
			cur=cur->left;
		else
			cur=cur->right;
	}
	if(key < prev->info)
		prev->left=temp;
	else
		prev->right=temp;
	return root;
}

nodeptr findmin(nodeptr root){
	nodeptr cur;
	for(cur=root;cur->left!=NULL;cur=cur->left);
	return cur;
}

nodeptr deletenode(nodeptr root, int key){
	nodeptr temp;
	if(root==NULL)
		return root;
	if(key < root->info)
		root->left=deletenode(root->left,key);
	else if(key > root->info)
		root->right=deletenode(root->right,key);
	else{
		if(root->left==NULL&&root->right==NULL)
			root=NULL;
		else if(root->left==NULL){
			temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL){
			temp=root;
                        root=root->left;
                        free(temp);
		}
		else{
			temp=findmin(root->right);
			root->info=temp->info;
			root->right=deletenode(root->right,temp->info);
		}
	}
	return root;
}

void preorder(nodeptr root){
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->left);
	preorder(root->right);
}

void postorder(nodeptr root){
	if(root==NULL)
                return;

        postorder(root->left);
        postorder(root->right);
	printf("%d ",root->info);
}

void inorder(nodeptr root){
	if(root==NULL)
                return;

        inorder(root->left);
	printf("%d ",root->info);
        inorder(root->right);
}

int main(){
	nodeptr root;
	int key,ch;
	root=getnode();
	root=NULL;
	while(1){
		printf("\n1:Insert into binary tree\n2:Delete from binary tree\n3:print preorder\n4:print postorder\n5:print inorder\n6:Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter element: "); scanf("%d",&key); root=createbst(root,key); break;
			case 2: printf("Enter element: "); scanf("%d",&key); root=deletenode(root,key); break;
			case 3: printf("Preorder Traversal: "); preorder(root); break;
		        case 4: printf("Postorder Traversal: "); postorder(root); break;
		        case 5: printf("Inorder Traversal: "); inorder(root); break;
			default: exit(1);
		}
	}
	return 0;
}