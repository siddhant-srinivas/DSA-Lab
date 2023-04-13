#include<stdio.h>

long binSearch(long arr[], long l, long r, long x);

long func(long a, long b);
int main()
{
    long n;
    scanf("%ld", &n);
    long array[n];
    for(long i = 0; i < n; i++)
    {
        array[i] = i+1;
    }
    printf("%ld", (long)binSearch(array, 0, n-1, n) +1);
}

long func(long a, long b)
{
    if((long)(a/b) == b) return 1;
    else if(((long)(a/b) > b ) && ((long)(a/(b+1)) < b+1 )) return 1;
    else if((long)(a/b) < b) return -1;
    else if((long)(a/b) > b) return 0;
}

long binSearch(long arr[], long l, long r, long x)
{
    if(r>=1) {
        long mid = (l + r)/2;
 
        if(func(x,arr[mid]) == 1) return mid;
        
        if(func(x,arr[mid]) == -1) return binSearch(arr, l, mid, x);
        
        if(func(x,arr[mid]) == 0) return binSearch(arr, mid+1, r, x);
    }
    if(r == 0) return 0;
}