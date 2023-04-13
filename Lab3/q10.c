#include <stdio.h>
#include <stdlib.h>

int plankSize(int arr[], int l, int r, int n, int k);

void main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    if (sum >= k)
    {
        int size = plankSize(arr, 1, max, n, k);
        printf("%d", size);
    }
    else
    {
        printf("0");
    }
}

int plankSize(int arr[], int l, int r, int n, int k)
{
    int mid, sum = 0;
    if (r >= l)
    {
        mid = (l + r) / 2;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i] / mid; 
        }
        if (sum == k)
        {
            return mid;
        }
        else if (sum > k)
        {
            plankSize(arr, mid + 1, r, n, k); // Increase size of each plank since number of planks is too much
        }
        else
        {
            plankSize(arr, l, mid - 1, n, k); 
        }
    }
}