#include <stdio.h>
int count = 1;
void subset(int n, int d, int s[])
{
    int x[10];
    int sum;
    int i, k;

    for(i = 1; i <= n; i++)
        x[i] = 0;
    sum = 0;
    k = 1;
    x[k] = 1;
    while(1)
        {
        if(k <= n && x[k] == 1)
            {
            if(sum+s[k] == d)
            {
            count++;
            printf("Solution is \n");
            for(i = 1; i <= n; i++)
                {
                if(x[i] == 1)
                    printf("%5d", s[i]);
                }
            printf("\n");
            x[k] = 0;
            }
            else if(sum + s[k] < d)
                sum += s[k];

            else
                x[k] = 0;
            }
        else
            {
            k--;
            while(k > 0 && x[k] == 0)
                k--;
            if(k == 0)
                break;
            x[k] = 0;
            sum = sum - s[k];
            }
        k = k + 1;
        x[k] = 1;
        }
    }

int main()
{
int n; //No. of elements in set
int d; //Required subset sum
int s[10]; //Array: Elements in the set
int i;
int sum = 0;

printf("Enter the value of n");
scanf("%d",&n);

printf("Enter the set in increasing order\n");
for(i=1;i<=n;i++)
{
scanf("%d",&s[i]);
sum += s[i];
}

printf("Enter the maximum subset value of d: ");
scanf("%d",&d);

if(sum < d)
printf("Solution NOT possible.\n");
else
{
if(count == 0)
printf("No solutions possible.");
else
subset(n, d, s);
}
return 0;
}
