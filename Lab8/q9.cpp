#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    map<int, int> losses;
    for(int i = 0; i<n; i++)
    {
        int winner, loser;
        cin >> winner >> loser;
        losses[loser]++;
    }
    for(int i = 1; i<=k; i++)
    {
        if(losses[i] <= 1) cout << i << " ";
    }
}