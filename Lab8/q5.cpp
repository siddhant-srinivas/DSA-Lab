#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> v(n);
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
    }
    map <int, int> freq;
    for(int i = 0 ; i<m; i++)
    {
        freq[v[i]]++;
    }
    set <int> s;
    for(auto i : freq) s.insert(i.first);
    for(int i = 1; i + m - 1 <= n; i++)     // covers all combinations of m elements
    {
        cout << (s.empty() ? -1 : *s.rbegin()) << endl;     // sets work in ascending order so starting from the back

        if(--freq[v[i-1]] == k) s.insert(v[i-1]);       // elem included after moving forward 1 place to include next m elements
        else if(s.find(v[i-1]) != s.end()) s.erase(v[i-1]);     

        if(++freq[v[i+m-1]] == k) s.insert(v[i+m-1]);
        else if(s.find(v[i+m-1]) != s.end()) s.erase(v[i+m-1]);
    }
    return 0;
}   