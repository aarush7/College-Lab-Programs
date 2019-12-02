#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int mul(int a,int b)
{
return(a*b);
}
int quo(int a,int b)
{
if(b==0)
{printf("divide by zero error");
exit(0);
}
else
return(a/b);
}

