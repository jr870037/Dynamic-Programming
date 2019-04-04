#include<stdio.h>
#define INF 1000
#define V 4 // number of matrix to be multiplied
void main()
{
    int n=V+1;
    int m[n][n],s[n][n],i,j,k,l,q;
    int p[n];
    printf("\nEnter the dimensions:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]: ",i);
        scanf("%d",&p[i]);
    }
    for(i=1;i<n;i++)
    m[i][i]=0;
    for(l=2;l<n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INF;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    printf("\nMin multiplication: %d",m[1][V]);
    printf("\nSplit at matrix: %d",s[1][V]);
}