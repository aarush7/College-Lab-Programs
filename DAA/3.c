
#include <stdio.h>
#include <stdlib.h>

void dfs(int a[20][20],int n,int v[],int source)
{
    int i;
    v[source]=1;
    printf("Visited %d\n",source);
    for(i=0;i<n;i++)
    {
        if(a[source][i]==1 && v[i]==0)
            dfs(a,n,v,i);
    }
}
void bfs(int a[20][20],int n, int v[],int source)
{
    int i,q[10],f=0,r=-1,nd;
    v[source]=1;
    printf("Visited %d\n",source);
    q[++r]=source;
    while(f<=r)
    {
        nd=q[f++];
        for(i=0;i<n;i++)
        {
            if(a[nd][i]==1 && v[i]==0)
            {
                q[++r]=i;
                v[i]=1;
                printf("Visited %d\n",i);
            }
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
    printf("By DFS\n");
    for(i=0;i<n;i++)
        if(v[i]==0)
    {
        //dfs(a,n,v,i);
        dfs(a,n,v,i);
        count++;
    }
    if(count==1)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is disconnected, no. of components=%d",count);



    printf("By BFS:\n");
    count=0;
    for(i=0;i<n;i++)
        v[i]=0;
    for(i=0;i<n;i++)
        if(v[i]==0)
    {
        bfs(a,n,v,i);
        //bfs(a,n,v,i);
        count++;
    }
    if(count==1)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is disconnected, no. of components=%d",count);
    return 0;
}
