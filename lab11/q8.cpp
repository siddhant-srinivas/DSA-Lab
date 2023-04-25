#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() 
{
    string s;
    cin >> s;
    int n = s.length();
    stack <int> st;
    st.push(-1);    // initializing stack with -1
    int max_len = 0;
    for (int i = 0; i < n; i++) 
    {
        if (s[i] == '(') 
            st.push(i);     
        else 
        {
            st.pop();       // pop index of last '(' from stack
            if (st.empty()) 
                st.push(i);     // push index of current ')' to stack
            else 
            {
                max_len = max(max_len, i - st.top());   // calculate length of RBS
            }                                      
        }
    }
    cout << max_len << endl;
    return 0;
}