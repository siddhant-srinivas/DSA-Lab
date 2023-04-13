#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
struct Compare
{
    bool operator()(pii a, pii b)
    {
        return a.first > b.first;
    }
};

int n_trains(vector <pii> trains)
{
    priority_queue<pii, vector<pii>, Compare> pq;
    int n = trains.size();
    for(int i = 0; i<n; i++)
    {
        pq.push(trains.at(i));
    }
    for(int i = 0; i<n ; i++)
    {
        trains.at(i) = pq.top();
        pq.pop();
    }
    priority_queue<int, vector<int>, greater<int>> p;   //Implementation of min heap
    int count = 1;
    p.push(trains.at(0).second);
    for(int i = 1 ; i<n; i++)
    {
        if(p.top() >= trains.at(i).first)
        {
            count++;
        }
        else
        {
            p.pop();
        }
        p.push(trains.at(i).second);
    }
    return count; 
}

int main()
{
    int n;
    cin >> n;
    int arr, dep;
    vector<pii> trains;
    for(int i = 0; i<n; i++)
    {
        cin >> arr >> dep;
        trains.push_back({arr, dep});
    }
    cout << n_trains(trains) << endl;
}
