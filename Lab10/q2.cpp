#include <iostream>
using namespace std;

int main()
{
    int m, n, v;
    cin >> m >> n;
    int a[m][n];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> v;
    int i = 0, j = n-1;
    while(i<m && j>=0)
    {
        if(a[i][j] == v)
        {
            cout << "YES" << endl; 
            return 0;
        }
        else if(a[i][j] > v)
            j--;
        else if(a[i][j] < v)
            i++;
    }
    cout << "NO" << endl;   // If it reaches this point we weren't able to find the value
    return 0;
}





