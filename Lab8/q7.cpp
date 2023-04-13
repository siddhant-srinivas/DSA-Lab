#include <algorithm>
#include <bits/stdc++.h>    // in case of error, change includePath settings (or use online gdb)
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i<n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    map<pair<int, int>, int> slope;
    int ans = 0;
    for(int i = 0; i<n; i++)
    {
        slope.clear();      // resets map to 0 in every iteration
        for(int j = i+1; j<n; j++)      
        {
            if (i == j)
                continue;
            int num = v[j].second - v[i].second;
            int den = v[j].first - v[i].first;
            int g = __gcd(num, den);

            slope[{num / g, den / g}]++;      // to reduce to simplest form, eg. (4/3 = 8/6)
        }
        int num = n - (i + 1);
        ans += num * (num - 1) / 2;

        for (auto s : slope)
        {
            ans -= s.second * (s.second - 1) / 2;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}