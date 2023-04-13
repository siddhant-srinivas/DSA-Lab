#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int gas_got[n];
    for(int i = 0; i<n; i++)
    {
        cin >> gas_got[i];
    }
    int gas_used[n];
    for(int i = 0; i<n; i++)
    {
        cin >> gas_used[i];
    }
    int start = 0;
    int total_gas_used = 0;
    int total_gas_got = 0;
    int curr_gas = 0;
    for(int i = 0; i<n; i++)
    {
        total_gas_got += gas_got[i];
        total_gas_used += gas_used[i];
        curr_gas += gas_got[i] - gas_used[i];
        if(curr_gas < 0)
        {
            start = i + 1;
            curr_gas = 0;
        }
    }
    if(total_gas_got >= total_gas_used)
    {
        cout << start << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}