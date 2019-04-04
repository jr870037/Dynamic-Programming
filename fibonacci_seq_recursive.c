#include<stdio.h>
#include<time.h>
int fibo(int n)
{
    if(n<=1)
    return n;
    return fibo(n-1)+fibo(n-2);
}
void main()
{
    clock_t t;
    t=clock();
    fibo(40);
    t=clock();
    printf("%lf",(double)t/CLOCKS_PER_SEC);
}