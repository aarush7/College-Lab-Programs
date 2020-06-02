#include <stdio.h>
#define INFINITY 999

void dijk(int cost[10][10],int n,int source,int v[10],int d[10])
{
int least, i, j, u;

v[source] = 1;

for(i=1; i<=n; i++)
{

 least = INFINITY;
 for(j=1; j<=n; j++)
  {
   if(v[j] == 0 && d[j] < least)
    {
     least = d[j];
     u = j;
   }
}

v[u] = 1;

for(j=1; j<=n; j++)
 {
if(v[j] == 0 && (d[j] > (d[u] + cost[u][j])) )
       d[j] = d[u] + cost[u][j];
 }
}

int main()
{
int n; //no. of nodes
int cost[10][10]; //Adjacency matrix of graph
int source;
int v[10];
int d[10];
int i, j;

printf("Enter n: ");
scanf("%d", &n);

printf("Enter Cost matrix: \n");
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
scanf("%d", &cost[i][j]);

printf("Enter Source: ");
scanf("%d", &source);

for(i=1; i<=n; i++)
{
d[i] = cost[source][i];
v[i] = 0;
}

dijk(cost, n, source, v, d);

printf("Shortest distance from source %d\n\n",source);
for(i=1; i<=n; i++)
printf("%d --> %d = %d \n\n", source, i, d[i]);
return 0;
}
