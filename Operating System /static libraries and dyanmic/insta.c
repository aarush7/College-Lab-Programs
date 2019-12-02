#include<stdio.h>
#include<stdlib.h>
int main()
{
int a,b;
printf("enter two inte");
scanf("%d%d",&a,&b);
printf("\nsum=%d",add(a,b));
printf("\nsub=%d",sub(a,b));
printf("\nm=%d",mul(a,b));
printf("\nq=%d",quo(a,b));
return 0;
}
