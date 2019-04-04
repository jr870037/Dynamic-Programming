#include <stdio.h>
#include <string.h>
#define M 10
#define N 10
int memo[M][N];
int lcs(char *, char *, int, int);
int max(int, int);
void initilizememo();
void printmemo(int,int);
void main()
{
    char A[] = "AGGTAB";
    char B[] = "GXTXAXB";
    int m = strlen(A) + 1, n = strlen(B) + 1, len = 0;
    initilizememo();
    len = lcs(A, B, 0, 0);
    printf("\nLength of lcs: %d\n", len);
    // printmemo(m,n);
}
void initilizememo()
{
    for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
    memo[i][j]=-1;
}
void printmemo(int m,int n)
{
    printf("\n\nPrinting memo:\n");
    for(int i=0;i<m;i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(memo[i][j]!=-1)
            printf(" %d\t",memo[i][j]);
            else
                printf("%d\t", memo[i][j]);
        }
        printf("\n");
    }
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int lcs(char *A, char *B, int i, int j)
{
    if(memo[i][j]!=-1)
    return memo[i][j];
    else if (A[i] == '\0' || B[j] == '\0')
        return memo[i][j]=0;
    else if (A[i] == B[j])
        return memo[i][j]=(1 + lcs(A, B, i + 1, j + 1));
    else
        return memo[i][j]=max(lcs(A, B, i + 1, j), lcs(A, B, i, j + 1));
}
