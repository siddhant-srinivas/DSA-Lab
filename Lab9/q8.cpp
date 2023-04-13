#include <iostream>

using namespace std;

bool is_possible(int *books, int n, int m, int minimum)
{
    int students = 1;
    int current_pages = 0;
    for(int i = 0; i<n; i++)
    {  
        if(books[i] > minimum)
        {
            return false;
        }
        if(current_pages + books[i] > minimum)
        {
            students++;
            current_pages = books[i];
            if(students > m)
            {
                return false;
            }
        }
        else
        {
            current_pages += books[i];
        }
    }
    return true;
}

int find_min(int *books, int n, int m)
{
    int total_pages = 0;
    int min_possible = 0;
    int max_possible = 0;
    for(int i = 0; i<n; i++)
    {
        total_pages += books[i];
        min_possible = max(min_possible, books[i]);
    }
    max_possible = total_pages;
    int ans = min_possible;
    while(min_possible <= max_possible)
    {
        int mid = (min_possible + max_possible)/2;
        if(is_possible(books, n, m, mid))
        {
            ans = mid;
            max_possible = mid - 1;
        }
        else
        {
            min_possible = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int books[n];
    for(int i = 0; i<n; i++)
    {
        cin >> books[i];
    }
    cout << find_min(books, n, m) << endl;
}