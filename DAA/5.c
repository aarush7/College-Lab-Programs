#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int len,a[1000],count=0,n;
void heapify(int a[],int i)
{

    int flag=0,k=i,v=a[i],j;
    while(!flag && 2*k<=len)
    {
        count++;
        j=2*k;
        if(j<len)
        {
            if(a[j]<a[j+1])
                j++; //j=j+1
        }
        if(v>=a[j])
            flag=1;
        else{
            a[k]=a[j];
            k=j;
        }
    }
    a[k]=v;
}
void heap(int a[])
{

    int i,t;
    for(i=len/2;i>0;i--)
    {
        heapify(a,i);
    }

    for(i=len;i>=2;i--)
    {
        count++;
        t=a[1];
        a[1]=a[len];
        a[len]=t;
        len--;
        heapify(a,1);
    }
}
int main()
{

    int i,j,b[1000],c[1000],c1=0,c2=0,c3=0;
    printf("Enter no.of elements:");
    scanf("%d",&n);
    len=n;
    printf("\nEnter the elements:\n");
    for(i=1;i<=len;i++)
        scanf("%d",&a[i]);
    heap(a);
    printf("Sorted Array:\n");
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);
    printf("No. of iterations:%d\n",count);
    count=0;
    //analysis
    printf("\nSize\tAscending\tDescending\tRandom\n");
    for(i=8;i<1000;i=i*2)
    {
        for(j=1;j<=i;j++)
        {
            a[j]=j;
            b[j]=i-j+1;
            c[j]=(rand()%i)+1;
        }
        count=0;
        len=i;
        heap(a);
        c1=count;
        count=0;
        len=i;
        heap(b);
        c2=count;
        count=0;
        len=i;
        heap(c);
        c3=count;
        printf("%d\t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
    }
    return 0;
}
