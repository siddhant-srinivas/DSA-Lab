#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    set <int> ones;
    for(int i = 0; i<q; i++)
    {
        int type, k;
        cin >> type >> k;
        switch(type)
        {
            case 1:
            {
                if(ones.find(k) == ones.end())  // absence of elem in set
                {
                    ones.insert(k);
                }
                else
                {
                    ones.erase(k);  // deletion of ones
                }
                break;
            }
            case 2:
            {
                auto x = lower_bound(ones.begin(), ones.end(), k);  
                if(x == ones.end())     // absence of req elem
                {
                    cout << "-1\n";
                }
                else
                {
                    cout << (*x) << endl;
                }
                break;
            }
            case 3:
            {
                auto x = upper_bound(ones.begin(), ones.end(), k);
                if(x == ones.begin())       // absence of req elem
                {  
                    cout << "-1\n";
                }
                else
                {
                    --x;
                    cout << (*x) << endl;
                }
                break;
            }
            default:
                break;
        }
    }
}
