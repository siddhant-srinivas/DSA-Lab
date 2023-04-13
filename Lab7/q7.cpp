#include <iostream>
#include <queue>

using namespace std;
int main()
{
    priority_queue<int> q;
    int n, k, elem;
    cin >> n >> k;
    int satisfaction = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> elem;
        q.push(elem);
    }
    for(int i = 0; i<k; i++)
    {
        elem = q.top();
        satisfaction += (elem + 1)/2;
        elem -= (elem + 1)/2;
        q.pop();
        q.push(elem);
    }
    cout << satisfaction << endl;
}