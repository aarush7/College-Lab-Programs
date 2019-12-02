#include <stdio.h>
#include <stdlib.h>

void maxheapify(int arr[],int n);
int extractmax(int arr[]);
void buildheap(int arr[]);
int n;
int main()
{

int i,a[10],ch;
for(;;)
{

    printf("\n1-Build heap\n2-Extract max\n3-exit\n");
    scanf("%d",&ch);
    switch(ch)
    {

    case 1: printf("read value of n\n");
            scanf("%d",&n);
            printf("enter the elements\n");
            for(i=1;i<=n;i++)
                scanf("%d",&a[i]);
            buildheap(a);
            printf("heap after insertion is \n");
            for(i=1;i<=n;i++)
                printf("%d ",a[i]);
            break;
    case 2: printf("max element retrieved is %d \n",extractmax(a));
            printf("heap after deletion is \n");
            for(i=1;i<=n;i++)
                printf("%d ",a[i]);
            break;
    case 3: exit(0);
}
}
return 0;
}

void buildheap(int a[])
{
    int i;
    for(i=n/2;i>=1;i--)
        maxheapify(a,i);
}

void maxheapify(int a[],int i)
{
    int left=2*i,right=2*i+1,largest;

    if(left<=n&&a[left]>a[i])
        largest=left;
    else largest=i;
    if(right<=n&&a[right]>a[largest])
        largest = right;

    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;

        maxheapify(a,largest);
    }
}

int extractmax(int a[])
{

    int max;
    if(n==0)
    {
        printf("empty heap\n");
        return -1;
    }
    else
    {
        max=a[1];
        a[1]=a[n];
        n=n-1;
        maxheapify(a,1);
        return max;
    }
}
