#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int A[m][n], B[m][n]; 
    
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            B[i][j] = 0;
        }
    }

    int ri, ci, rh, ch;   
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);

    for(int x = 0; x<m; x++)
    {
        for(int y = 0; y<n; y++)
        {    
            for(int i = 0; i <= x; i++)
            {
                if(i == x)
                {
                    for(int j = 0; j <= y; j++)
                    {
                        B[x][y] = B[x][y] + A[i][j]; 
                    }
                }
                else if(i != x)
                {
                    for(int j = 0; j < n; j++)
                    {
                        B[x][y] = B[x][y] + A[i][j]; 
                    }
                }
            }    
        printf("%d ", B[x][y]); 
        }
        
        printf("\n");
    }
    
    if(n-ci<ch || m-ri<rh)
    {
        printf("NOT POSSIBLE");
    }
    
    else 
    {
        int sum = 0;
        for(int i = ri; i<m; i++)
        {
            for(int j = ci; j<n; j++)                
            {
                sum = sum + B[i][j];
            }
        }

    printf("%d", sum);
    }
}