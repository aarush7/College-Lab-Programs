#include<stdio.h>
#include<stdlib.h>
int count=0;
#define SIZE 1000
int b[SIZE];
void merge(int a[],int l,int m,int h)
{
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m && j<=h)
    {    count++;
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=m)
    {    count++;
        b[k++]=a[i++];
    }
    while(j<=h)
    {    count++;
        b[k++]=a[j++];
    }
    for(i=l;i<=h;i++)
        a[i]=b[i];
}
void mergesort(int a[],int l,int h)
{
    int mid;
    if(l<h)
    {    mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
    int a[SIZE],b[SIZE],c[SIZE];
    int c1,c2,c3,n,i;
    printf("\nEnter no. of elements:");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Sorting...\n");
    mergesort(a,0,n-1);
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("No. of iterations=%d\n",count);
    //analysis
    printf("\nSize\tAcsending\tDescending\tRandom\n");
    int j;
    for(i=16;i<1000;i=i*2)
    {
        for(j=1;j<=i;j++)
        {
            a[j]=j;
            b[j]=i-j+1;
            c[j]=(rand()%i)+1;
        }
        count=0;
        mergesort(a,1,i);
        c1=count;
        count=0;
        mergesort(b,1,i);
        c2=count;
        count=0;
        mergesort(c,1,i);
        c3=count;
        printf("%d\t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
    }
    return 0;
}
