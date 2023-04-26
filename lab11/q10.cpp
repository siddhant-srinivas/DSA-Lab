#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool t[n+1][k+1];
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= k; j++)
        {
            if(i == 0)
                t[i][j] = false;
        }
    }

    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= k; j++)
        {
            if(j == 0)
                t[i][j] = true;
        }
    }
    for(int i = 1;i < n + 1;i++)
    {
        for(int j = 1;j < k + 1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=(t[i-1][j-arr[i-1]]||t[i-1][j]);
            else
            {
               t[i][j]=t[i-1][j];
            }
        }
    }

    if(t[n][k])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
