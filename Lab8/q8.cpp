#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = (int) s.length();
    map<string, int> freq;      // frequency of occurrence of substrings
    for(int i = 0; i<n-9; i++)  
    {
        freq[s.substr(i,10)]++;
    }
    int count = 0;
    for(auto i : freq)
    {
        if(i.second > 1) count ++;      
    }
    cout << count << endl;      // number of substrings that occur more than once
    for(auto i : freq)
    {
        if(i.second > 1)    cout << i.first << endl;        // first represents substring, second represents its freq
    }
}