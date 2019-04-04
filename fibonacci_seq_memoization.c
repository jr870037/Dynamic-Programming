#include<stdio.h>
#include<time.h>
#define MAX 41
int memo[MAX];
int fibo(int n)
{
    if(memo[n]==-1)
    {
        if(n<=1)
        memo[n]=n;
        else
        memo[n]=fibo(n-1)+fibo(n-2);
    }
    return memo[n];
}
void main()
{
    for(int i=0;i<MAX;i++)
    memo[i]=-1;
    clock_t t;
    t=clock();
    fibo(40);
    t=clock();
    printf("%lf",(double)t/CLOCKS_PER_SEC);
}