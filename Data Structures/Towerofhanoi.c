#include <stdio.h>

int count=0;
void TowerOfHanoi(int n,int source,int destination,int temporary){
	if(n==1){
		printf("\nDisk %d moved from tower \"%d\" to tower \"%d\" ",n,source,destination);
		++count;
	}
	else{
		TowerOfHanoi(n-1,source,temporary,destination);
		printf("\nDisk %d moved from tower \"%d\" to tower \"%d\" ",n,source,destination);
		++count;
		TowerOfHanoi(n-1,temporary,destination,source);
	}
}

int main(){
	int n,source,destination,temporary;
	printf("\nEnter number of disks to be arranged according to Tower Of Hanoi : ");
	scanf("%d",&n);
	TowerOfHanoi(n,1,3,2);
	printf("\nTotal number of shifts are equal to %d\n",count);
	return 0;
}

