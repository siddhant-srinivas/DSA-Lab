#include<stdio.h>
int compare(int x, int y, int s, int t, int Arr1[x][y], int Arr2[s][t]);
int main()
{
    int m, n, p, q;
    scanf("%d %d", &m, &n);
    int A[m][n];
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++)
        {   scanf("%d", &A[i][j]);  }
    }
    scanf("%d %d", &p, &q);
    int B[p][q];
    for(int i = 0; i<p; i++)
    {
        for(int j = 0; j<q; j++)
        {   scanf("%d", &B[i][j]);  }
    }
    int test = compare(m, n, p, q, A, B);
    switch(test)
    {
        case 0: printf("NO");
                break;
        case -1: printf("PARTIAL");
                break;
        case 1: printf("YES");
                break;                
    }
}
int compare(int x, int y, int s, int t, int arr1[x][y], int arr2[s][t])
{
    int flag = 0;
    int par = -1;
    for(int i = 0; i<s-1 ; i++)     
    {   
        for(int j = 0; j<t-1; j++)      
        {   
            int f = 0;
            for(int a = 0; a<x && (!f); a++)
            {
                for(int b = 0; b<y && (!f); b++)
                {
                    if(((arr2[i][j] == arr1[a][b]) && (arr2[i][j+1] == arr1[a][b+1]))
                        || ((arr2[i][j] == arr1[a][b]) && (arr2[i+1][j] == arr1[a+1][b])))
                        {
                            flag = 1;
                            if((arr2[i][j] == arr1[a][b] && arr2[i][j+1] == arr1[a][b+1])
                                && (arr2[i+1][j] == arr1[a+1][b] && arr2[i+1][j+1] == arr1[a+1][b+1]))                               
                                {par = 1; f = 1;}
                            else return -1;
                        }     
                }
            }  
        }
    }
    if(flag == 1) return par;
    else if(flag == 0) return flag;
}