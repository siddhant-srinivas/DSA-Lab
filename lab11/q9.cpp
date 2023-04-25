#include <iostream>
using namespace std;

int a[5005];
int dp[5005][5005];

int main() 
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++) 
    {
        cin >> a[i];
        dp[i][i] = a[i];
    }

    for (int len = 2; len < n + 1; len++) 
    {
        for (int i = 1; i <= n-len+1; i++) 
        {
            int j = i+len-1;
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}