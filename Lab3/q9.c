#include<stdio.h>

long comp(long a, long n);
long binarySearch(long arr[], long l, long r, long x);

int main()
{
    long n;
    scanf("%ld", &n);
    long arr[n]; long arr2[n];
    long halfComparisons = comp(n,n)/2l;
    for(long i = 0; i<n; i++)
    {
        arr2[i] = comp(i+1,n);
    }
    long index = binarySearch(arr2, 0, n-1, halfComparisons);
}

long binarySearch(long arr[], long l, long r, long x)
{
    if(r>=1)
    {
        long mid = (l+r)/2;
        if(arr[mid] == x) return mid+1;
        else if(arr[mid] < x) return binarySearch(arr, mid+1, r, x);
        else if(arr[mid] > x) return binarySearch(arr, l, mid, x);
    }
}

long comp(long a, long n)
{
    long sum = n-1;
    long val = n-1;
    for(long i = 1; i<a; i++)
    {
        sum = sum + val - 1;
        val = val - 1;
    }
    return sum;
}