#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for(int i = 0 ; i<n; i++)
    {
        cin >> a[i];
    }
    vector <int> s(n+1, 0);
    for(int i = 1 ; i < n + 1; i++)
    {
        s[i] = s[i-1] + a[i-1];
    }
    int ans = 0;
    for(int i = 1; i < n + 1; i++)
    {
        int lb = *lower_bound(s.begin(), s.end(), s[i] - k);
        ans += i - lb;
    }
    cout << ans << endl;
}