#include <iostream>
#include <vector>
using namespace std;
#define int long long

int32_t main()
{
    int n, W;
    cin >> n >> W;
    vector<int> weights(n);
    vector<int> values(n);
    int V = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> weights[i] >> values[i];
        V += values[i];
    }
    int dp[n + 1][V + 1];
    for(int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 1; i < V + 1; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < V + 1; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < V + 1; j++)
        {
            if(j >= values[i - 1]) 
                dp[i][j] = min(dp[i][j], dp[i-1][j - values[i - 1]] + weights[i - 1]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }
    for(int i = 0; i < V + 1; i++)
    {
        if(dp[n][V - i] <= W) 
        {
            cout << V - i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}