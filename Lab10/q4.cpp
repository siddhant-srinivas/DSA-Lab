#include <iostream>
#include <vector>

using namespace std;

void pancake_flip(vector<int>& arr, int k)
{
    int i = 0;
    int j = k - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

int find_max_index(vector<int>& arr, int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[max]) 
            max = i;
    }
    return max;
}

vector<int> pancake_sort(vector<int>& arr)
{
    int n = arr.size();
    vector<int> flips;

    for (int i = n; i > 1; i--)
    {
        int maxIndex = find_max_index(arr, i);

        if (maxIndex != i - 1)
        {
            if (maxIndex != 0)
            {
                pancake_flip(arr, maxIndex + 1);
                flips.push_back(maxIndex + 1);
            }
            pancake_flip(arr, i);
            flips.push_back(i);
        }
    }

    return flips;
}

int main()
{   
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)
    {
        cin >> arr.at(i);
    }
    vector<int> flips = pancake_sort(arr);
    cout << flips.size() << endl;
    for (int flip : flips)
    {
        cout << flip << " ";
    }
    cout << endl;

    return 0;
}