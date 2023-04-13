#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map <int, int> freq;
    int x = 0;
    int ans = 0;
    for(int i = 0; i<n; i++)
    {
        x ^= v[i];
        ans += freq[x]++;
    }
    cout << ans + freq[0] << endl;
}