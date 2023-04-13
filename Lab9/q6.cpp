#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, elem, diff, min = 9999999;
    cin >> n >> diff;
    priority_queue <int> q1;
    priority_queue <int> q2;
    for(int i = 0; i<n; i++)
    {
        cin >> elem;
        q1.push(elem);
        if(elem < min) min = elem;
    }
    int required = min + diff;
    while(!q1.empty() && q1.top() >= required)
    {
        q2.push(q1.top());
        q1.pop();
    }
    int count = 0;
    while(!q1.empty() && !q2.empty())
    {
        if(q2.top() - q1.top() >= diff)
        {
            count++;
            q2.pop();
        }
        q1.pop();
    }  
    cout << count << endl;
}