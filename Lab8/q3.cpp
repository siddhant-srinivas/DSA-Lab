#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i<n; i++)
    {
        cin >> input[i];
    }
    int x, y;
    cin >> x >> y;
    int inputy[n];      // aj - yj array
    for(int j = 0; j<n; j++)
    {
        inputy[j] = input[j] - y * j;
    }
    int inputx[n];      //ai - xi array
    for(int i = 0; i<n; i++)
    {
        inputx[i] = input[i] - x * i;
    }
    int ans = 0;
    map <int, int> store;       // map of j
    for(auto x: inputy) store[x]++;
    for(int i = 0; i<n; i++)
    {
        store[inputy[i]]--;     // remove element from map which corresponds to y
        ans += store[inputx[i]];        
    }
    cout << ans << endl;
}