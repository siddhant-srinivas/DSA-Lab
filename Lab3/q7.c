#include <stdio.h>

int binSearch(int arr[], int l, int r, int x);
int main()
{
    int n, max;
    scanf("%d %d", &n, &max);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", binSearch(arr, 0, n-1, max));
}

int binSearch(int arr[], int l, int r, int x)
{
        int mid = (l+r)/2;
        if(l == r) return arr[r];
        if((arr[mid] <= x) && (arr[mid + 1] > x)) return arr[mid];
        
        else if((arr[mid] < x) && (arr[mid + 1] < x)) return binSearch(arr, mid+1,r,x);
        
        else if((arr[mid] > x) && (arr[mid - 1] < x)) return arr[mid-1];
        
        else if((arr[mid] > x) && (arr[mid - 1] > x)) return binSearch(arr, l, mid-1, x);
}