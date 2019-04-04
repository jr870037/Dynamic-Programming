#include<stdio.h>
#include<string.h>
int lcs(char*,char*,int,int);
int max(int,int);
void main()
{
    char A[]="bcd";
    char B[]="bd";
    int m = strlen(A) + 1, n = strlen(B) + 1, len = 0;
    len=lcs(A,B,0,0);
    printf("Length of lcs: %d",len);

}
int max(int a,int b)
{
    return (a>b)?a:b;
}
int lcs(char *A,char*B,int i,int j)
{
    if(A[i]=='\0'||B[j]=='\0')
    return 0;
    else if(A[i]==B[j])
    return (1+lcs(A,B,i+1,j+1));
    else 
    return max(lcs(A,B,i+1,j),lcs(A,B,i,j+1));
}
