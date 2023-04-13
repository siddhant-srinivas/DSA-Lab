#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    map <vector<int>, int> ma;
    for(int i = 0 ; i < n; i++)
    {
        string s; 
        cin >> s;
        vector<int> freq(26,0); // represents number of occurrences of all the alphabets
        for(char c : s)
        {
            freq[c - 'a']++;
        }
        ma[freq]++; // anagrams have same key value
    }
    int ans = 0;
    for(auto i : ma)
    {
        int k = i.second;
        ans += (k * (k-1))/2;   // number of combinations per anagram
    }
    cout << ans << endl;
}  