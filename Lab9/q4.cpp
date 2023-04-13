#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    long long ans = 0;
    map<long long, int> count;
    count[0] = 1;
    long long sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += arr[i];
        ans += count[sum - k * (i + 1)];
        count[sum - k * (i + 1)]++;
    }
    cout << ans << endl;
}