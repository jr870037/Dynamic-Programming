#include<stdio.h>
#include<time.h>
#define MAX 41
int table[MAX];
int fibo(int n)
{
    table[0]=0;
    table[1]=1;
    for(int i=2;i<MAX;i++)
    {
        table[i]=table[i-1]+table[i-2];
    }
    return table[n];
}
void main()
{
    clock_t t;
    t=clock();
    fibo(5);
    t=clock();
    printf("%lf", (double)t / CLOCKS_PER_SEC);
}