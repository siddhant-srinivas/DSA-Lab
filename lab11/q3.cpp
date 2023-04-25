#include <iostream>
#include <vector>

using namespace std;

int func(int i,int j, string &s1,string &s2,vector<vector<int> > &dp)
{
    if(i<0) 
        return j+1;
    if(j<0) 
        return i+1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(s1[i]==s2[j]) 
        return dp[i][j]=func(i-1,j-1,s1,s2,dp);

    return dp[i][j] = (1+min(func(i-1,j,s1,s2,dp),min(func(i,j-1,s1,s2,dp),func(i-1,j-1,s1,s2,dp))));
}
int minDistance(string s1, string s2) 
{
    int n = s1.length();
    int m = s2.length();
    vector< vector<int> > dp(n, vector<int>(m,-1));
    return func(n-1, m-1, s1, s2, dp);
}

int main()
{
    int n, m;
    string s1, s2;
    cin>>n;
    cin>>s1;
    cin>>m;
    cin>>s2;
    cout<<minDistance(s1,s2);
}