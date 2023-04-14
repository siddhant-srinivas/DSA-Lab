#include <iostream>
using namespace std;

long long merge(int arr[], int temp[], int l, int mid, int r)       
{              
                                            // Merges 2 sorted subarrays and counts number of out of order pairs after merge
    int i = l; // Index for left subarray
    int j = mid;  // Index for right subarray
    int k = l; // Index for resultant merged array

    long long count = 0;
    while ((i <= mid - 1) && (j <= r)) 
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else 
        {
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }
    
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= r)
        temp[k++] = arr[j++];
 
    for (i = l; i <= r; i++)
        arr[i] = temp[i];
 
    return count;
}
 
long long merge_sort(int arr[], int temp[], int l, int r)       // Counts number of out of order pairs in the 2 halves and then
                                                                // in the merged array and adds them
{
    int mid;
    long long count = 0;
    if (r > l) 
    {
        mid = (l + r) / 2;
        count += merge_sort(arr, temp, l, mid);
        count += merge_sort(arr, temp, mid + 1, r);
        count += merge(arr, temp, l, mid + 1, r);
    }
    return count;
}
 
long long count_pairs(int arr[], int n) 
{
    int temp[n];
    for(int i = 0; i<n; i++)
    {
        temp[i] = 0;
    }
    return merge_sort(arr, temp, 0, n - 1);
}

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    long long ans = count_pairs(arr, n);
    cout << ans << endl;
    return 0;
}