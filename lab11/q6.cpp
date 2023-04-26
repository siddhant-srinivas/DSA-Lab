#include <iostream>
using namespace std;
int coupon_change(int coupons[], int n, int amount) 
{
    int t[n+1][amount+1]; 
    for(int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    } 
    for(int j = 0; j < amount + 1; j++)
    {
        t[0][j] = amount+1;
    }
 
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < amount + 1; j++) 
        {
            if(coupons[i-1] <= j)
                t[i][j] = min(1 + t[i][j-coupons[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][amount] > amount ? -1 : t[n][amount];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << coupon_change(arr, n, k) << endl;
    return 0;
}
