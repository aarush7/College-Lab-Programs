
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int board[10],count;

void print(int n)
{
  int i,j;
  printf("\n\n Solution %d\n\n",++count);
  for(i=1;i<=n;i++)
   printf("\t%d",i);
 for(i=1;i<=n;i++)
 {
   printf("\n\n%d",i);
   for(j=1;j<=n;j++)
   {
     if(board[i]==j)
       printf("\tQ");
     else
       printf("\t-");
   }
 }
}

int place(int row,int col)
{
int i;
for(i=1;i<=row-1;i++)
 {
  if(board[i]==col)
    return 0;
  else if(abs(board[i]-col) == abs(i-row))
    return 0;
 }
 return 1;
}

void nqueens(int row, int n)
{
  int col;
  for(col=1;col<=n;col++)
  {
     if(place(row,col))
      {
    board[row]=col;
    if(row == n)
       print(n);
    else
      nqueens(row+1,n);
      }
  }
}

int main()
{
  int n;
  printf("\n Enter the number of Queens :");
  scanf("%d",&n);
  if ( n==1 || n==2 || n==3)
    printf("\n no soultions");
  else
    nqueens(1,n);
 return 0;
}
