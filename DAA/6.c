#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define size 256
int table[size];
void shift_table(char p[])
{
    int i,j,m;
    m=strlen(p);
    for(i=0;i<size;i++)
        table[i]=m;
    for(j=0;j<=m-2;j++)
        table[p[j]]=m-1-j;
}
int horspool(char T[],char p[])
{
    int i,j,k,n,m;
    n=strlen(T);
    m=strlen(p);
    i=m-1;
    while(i<n)
    {
        k=0;
        while(k<m && p[m-1-k]==T[i-k])
            k++;
        if(k==m)
            return i-m+1;
        else
            i=i+table[T[i]];
    }
    return -1;
}
int main()
{
    char t[40],p[10];
    printf("Enter text:\n");
    scanf("%s",t);
    printf("Enter pattern:\n");
    scanf("%s",p);
    shift_table(p);
    int c=horspool(t,p);
    if(c==-1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at %d\n",c);
}
