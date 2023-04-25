#include <iostream>
#include <vector>
using namespace std;

int matrix_chain(vector<int>& v) 
{
    int n = v.size()-1;
    vector< vector<int> > m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        m[i][i] = 0;
    for (int a = 2; a <= n; a++) 
    {
        for (int i = 0; i < n-a+1; i++) 
        {
            int j = i+a-1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) 
            {
                int x = m[i][k] + m[k+1][j] + v[i]*v[k+1]*v[j+1];
                if (x < m[i][j])
                    m[i][j] = x;
            }
        }
    }
    return m[0][n-1];
}

int main() 
{
    int n;
    cin >> n;
    vector <int> v(n+1);
    for(int i = 0; i < n + 1; i++)
    {
        cin >> v[i];
    }
    int result = matrix_chain(v);
    cout << result << endl;
    return 0;
}







