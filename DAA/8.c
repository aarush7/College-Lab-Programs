#include<stdio.h>
#define INFINITY 999

void prims(int n,int cost[10][10],int source)
{
int v[10]; //visited . keeps track to nodes visited and not
int d[10]; //distance. keeps latest shortest distance from source
int i, j; //index variables
int vertex[10]; //keeps track of nearest node to spanning tree
int u, least, sum=0;

//1. Initialisation
for(i=1;i<=n;i++)
{
v[i] = 0; //visited array
d[i] = cost[source][i]; //distance array
vertex[i] = source; //nearest node to spanning tree
}
v[source] = 1; //mark source node as visited

//2. n iteration
for(i=1;i<n;i++)
{
    least = INFINITY;
//2a) Find u and d(u) such that d(u) is least
    for(j=1; j<=n; j++)
        {
                if(v[j] == 0 && d[j] < least)
                {
                        least = d[j];
                        u = j;
                }
        }
//2b) mark node u as visited
    v[u] = 1;
    sum += d[u];
    printf("%d --> %d = %d Sum = %d\n\n",vertex[u],u,d[u],sum);
//2c) update d[] array. Explore paths through node u.
    for(j=1;j<=n;j++)
    {
        if(v[j] == 0 && cost[u][j] < d[j])
        {
            d[j] = cost[u][j];
            vertex[j] = u;
        }
    }
}
printf("Total cost: %d",sum);
}
int main()
{
int n; //no. of nodes
int cost[10][10]; //Adjacency matrix of graph
int source; //source node
int i, j; //index variables
printf("Enter n (no. of nodes): ");
scanf("%d", &n);
printf("Enter cost matrix:\n ");
for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
        scanf("%d", &cost[i][j]);
printf("Enter Source: ");
scanf("%d", &source);
prims(n, cost, source);
return 0;
}
