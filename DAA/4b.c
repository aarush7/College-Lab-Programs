#include <stdio.h>
#include <stdlib.h>
int order[20],k=0;
void dfs(int a[20][20],int n,int v[],int source)
{
    int i;
    v[source]=1;
    //printf("Visited %d\n",source);
    for(i=0;i<n;i++)
    {
        if(a[source][i]==1 && v[i]==0)
        {

            dfs(a,n,v,i);
            order[k++]=i;
        }
    }
}
int main()
{
    int n,i,j,a[20][20],v[20];
    int count=0;
    printf("Enter value of n:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
        v[i]=0;
    for(i=0;i<n;i++)
        if(v[i]==0)
    {
        dfs(a,n,v,i);
        order[k++]=i;
    }
    printf("Topoligical order:");
    for(i=n-1;i>=0;i--)
    {
        printf("%d\t",order[i]);
    }
}
