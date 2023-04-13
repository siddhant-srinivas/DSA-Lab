#include <iostream>
#include <vector>
using namespace std;

struct doll 
{
    int w, h;
};

bool comp(doll d1, doll d2)
{
    if(d1.w == d2.w) 
        return d1.h > d2.h;        // '>' instead of '<' to ensure that dolls with equal widths won't fit
    return d1.w < d2.w;
}

int max_dolls(vector<doll>& dolls) 
{
    int n = dolls.size();
    if(n == 0) 
        return 0;

    sort(dolls.begin(), dolls.end(), comp);         // Sort dolls in ascending order of width in O(nlogn)

    /*for(int i = 0; i<n; i++)
    {
        cout << dolls.at(i).w << " " << dolls.at(i).h << endl;
    } */

    vector<int> arr(n, 1);                   // Initializing with 1 because 1 is base case
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)          // O(nlogn), not O(n^2) because dolls are sorted according to width
        {              
            if(dolls[j].h < dolls[i].h) 
                arr[i] = max(arr[i], arr[j]+1);        // dp[j] + 1 to include case where smaller doll fits in larger
        }
    }

    return *max_element(arr.begin(), arr.end());       // O(n)  
}

int main() 
{
    int n;
    cin >> n;
    vector <doll> dolls(n);
    for(int i = 0; i<n; i++)
    {
        int w, h;
        cin >> w >> h;
        dolls.at(i).w = w;
        dolls.at(i).h = h;
    }
    cout << max_dolls(dolls) << endl;
}