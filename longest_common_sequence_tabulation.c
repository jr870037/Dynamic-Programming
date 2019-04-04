//not generalized
#include <stdio.h>
#define MAX 4
void display_lcs_matrix(int lcs[][4], int n, int m);
void modify(int lcs[][4], int n, int m);
void longest_common_seq(int lcs[][4], int n, int m, char A[], char B[]);
int max(int a, int b);
void main()
{
    char A[5] = {
        ' ', 'a', 'b', 'd', '\0'};
    char B[4] = {
        ' ', 'b', 'd', '\0'};
    int n = 3, m = 4; // m is the number of  column and n is the number of rows.
    int lcs[n][m];
    modify(lcs, n, m);
    longest_common_seq(lcs, n, m, A, B);
    display_lcs_matrix(lcs, n, m);
}
void getdata()
{

}
void modify(int lcs[][4], int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (i == 0 || j == 0)
                lcs[i][j] = 0;
            else
                lcs[i][j] = -1;
    // lcs[i][j] = -1;
}
void display_lcs_matrix(int lcs[][4], int n, int m)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d\t", lcs[i][j]);
        printf("\n");
    }
    // while(i<m)
    // lcs[0][i++]=0;
    // while(j<n)
    // lcs[j++][0]=0;
}
int max(int a, int b)
{
    int x = 0;
    x = a > b ? a : b;
    return x;
}
void longest_common_seq(int lcs[][4], int n, int m, char A[], char B[])
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (B[i] == A[j])
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            else
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
        }
    }
}