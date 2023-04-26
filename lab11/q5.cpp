#include <iostream>
#include <cstring>
using namespace std;

int t[502][502];

int solve(int arr[], int i, int j)
{
    if(i >= j)
        return 0;

    if(t[i][j] != -1)
        return t[i][j];

    int min = INT_MAX;

    for(int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if(temp < min)
            min = temp;
    }
    return t[i][j] = min;
}

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    memset(t, -1, sizeof(t));
    cout << solve(arr, 1, n) << endl;
    return 0;
}
