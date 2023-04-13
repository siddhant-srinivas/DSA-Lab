#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(string a, string b)
    {
        return a + b < b + a;
    }
};

void printLexicographically(vector <int> &nums)
{
    priority_queue <string, vector<string>, Compare> pq;
    for(int i = 0; i<nums.size(); i++)
    {
        pq.push(to_string(nums[i]));
    }
    while(!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i = 0; i<n; i++)
    {
        cin >> nums.at(i);
    }
    printLexicographically(nums);
    return 0;
}
