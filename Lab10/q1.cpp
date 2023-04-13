#include <iostream>

using namespace std;

int max_mp_sum(int *arr, int l, int r)     // Maximum sum of subarray starting from midpoint and going in either or both directions
{
    int m = (l + r) / 2;
    int sum = 0;
    int leftSum = -9999999;
    int rightSum = -9999999;

    for(int i = m; i>=1; i--)
    {
        sum += arr[i];
        if(sum > leftSum)
            leftSum = sum;
    }

    sum = 0;

    for(int i = m + 1; i<=r; i++)
    {
        sum += arr[i];
        if(sum > rightSum)
            rightSum = sum;
    }

    return max(max(leftSum + rightSum, leftSum), rightSum);  // In case any of left or right sum is -ve, will return the other
}

int sum_subarray(int *arr, int l, int r)    /*  Recursively finds max for left and right halves and compares them 
                                                with sum of subarray crossing over midpoint of current array (max_sum) */
{
    if(l == r)
        return arr[l];
            // Base condition (single element)
    int m = (l + r) / 2;
    return max(max(sum_subarray(arr, l, m), sum_subarray(arr,m+1,r)), max_mp_sum(arr,l,r));
}

int main()
{
    int n;
    cin >> n;
    
    int arr[n+1];
    for(int i = 1; i<n+1; i++)
    {
        cin >> arr[i];
    }

    cout << sum_subarray(arr, 1, n);

    return 0;
}
