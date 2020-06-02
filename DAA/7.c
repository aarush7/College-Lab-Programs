#include<stdio.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    int n,m,i,j,w[10],p[10],v[10][10],x[10]={0};
    printf("Enter no. of objects:");
    scanf("%d",&n);
    printf("Enter weights:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("Enter profits:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("\nEnter knapsack capacity:");
    scanf("%d",&m);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                v[i][j]=0;
            else if(j-w[i]<0)
                v[i][j]=v[i-1][j];
            else
                v[i][j]=max(v[i-1][j],v[i-1][j-w[i]] + p[i]);
            printf("%d\t",v[i][j]);
        }
        printf("\n");
    }

    i=n,j=m;
    while(i!=0 && j!=0)
    {
        if(v[i][j]!=v[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i=i-1;
    }
    printf("\nThe solution is\n");
    printf("\nObject no.\tWeight\tProfit\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
            printf("\t%d\t%d\t%d\n",i,w[i],p[i]);
    }
    printf("The maximum profit is %d\n",v[n][m]);
    return 0;
}
