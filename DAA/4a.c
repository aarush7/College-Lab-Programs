#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,a[10][10],b[10],st[10],top=-1,nd;
    int v[10],result[10],k=0;
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
     v[i]=0;
     b[i]=0;
     result[i]=-1;
    }
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
            {
                b[j]++;
            }
        }
    for(i=0;i<n;i++)
        if(b[i]==0)
            st[++top]=i;
    while(top!=-1)
    {
        nd=st[top--];
        result[k++]=nd;
        v[nd]=1;
        for(i=0;i<n;i++)
        {
            if(a[nd][i]==1)
                b[i]--;
        }
        for(i=0;i<n;i++)
        {
            if(b[i]==0 && v[i]==0)
                st[++top]=i;
        }
    }
    printf("Order:");
    for(i=0;i<n;i++)
        printf("%d\t",result[i]);
    return 0;
}
