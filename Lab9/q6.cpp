#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = 0, j = 1, ans = 0;
    while (j < n) 
    {
        if (a[j] - a[i] >= k) 
        {
            ans++;
            i++;
            j++;
        } 
        else 
            j++;
    }
    cout << ans << endl;
    return 0;
}
