#include <iostream>
using namespace std;
 
int find_median(int *a, int n, int *b, int m)
{
    if(n > m)
        return find_median(b, m, a, n);

    int partition1, partition2, median;
    int l = 0, r = n;
     
    while (l <= r)
    {
        partition1 = (l + r) / 2;
        partition2 = ((n + m + 1) / 2) - partition1;
         
        if (partition2 < 0)
        {
            r = partition1-1;       // Partition 2 not possible so partition1 elements only
            continue;
        }
                // If partit1 = n, no elems in second half from a; If partit2 = 0, similarly for first half and b
        if (partition1 < n && partition2 > 0 && b[partition2 - 1] > a[partition1])       
            l = partition1 + 1;
                 
                // Similarly but first half and second half
        else if (partition1 > 0 && partition2 < m && b[partition2] < a[partition1 - 1])       
            r = partition1 - 1;
 
        else
        {
            // No elements in first half from a so we return last element in b from the first half
            if (partition1 == 0)          
                median = b[partition2 - 1];           
             
            // No elements in first half from b so we return last element in a from the first half
            else if (partition2 == 0)           
                median = a[partition1 - 1];           
            else           
                median = max(a[partition1 - 1], b[partition2 - 1]);           
            break;
        }
    }
     
    if ((n + m) % 2 == 1)
        return median;
         
            // No elements from a in second half 
    if (partition1 == n)
        return (median+b[partition2]) / 2;
         
            // No Elements from b in second half 
    if (partition2 == m)
        return (median + a[partition1]) / 2;
     
    return (median + min(a[partition1], b[partition2])) / 2;
}

int main()
{
    int n, m;
    cin >> n;
    int a[n];
    for(int i= 0; i<n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for(int i = 0; i<m; i++)
    {
        cin >> b[i];
    }
    cout << find_median(a, n, b, m) << endl;
}