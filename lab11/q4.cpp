#include <iostream>
#include <cstring>
#include <numeric>

using namespace std;

int dp[1005][1005], a[1005];        

int solve(int i, int j, int turn)       /*  dp stores maximum score difference that the turn'th player can get between the i-th
                                            and j-th elements of the array on his turn */
{
    if (i > j)      // Base condition
        return 0;
    if (dp[i][j] != -1)     // Typical memoization initialization
        return dp[i][j];
    if (turn == 1) 
        return dp[i][j] = max(a[i] + solve(i + 1, j, 2), a[j] + solve(i, j - 1, 2));    // Max of first & last element
    else 
        return dp[i][j] = min(solve(i + 1, j, 1), solve(i, j - 1, 1));  // To minimize score difference after 1st player's turn
}

int main() 
{
    int n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    int ans = solve(0, n - 1, 1);
    int sum = accumulate(a, a + n, 0);
    if (2 * ans >= sum)         // Equality indicates same score between players
        cout << "Vidyateja" << endl;
    else 
        cout << "Hom" << endl;
    return 0;
}
