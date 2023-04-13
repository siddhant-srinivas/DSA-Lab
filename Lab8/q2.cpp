#include <iostream>
#include <string>
using namespace std;
void nextPalin(int arr[], int n)
{
    int mid = n/2;
    int i = mid - 1;
    int j = (n % 2) == 0 ? mid : mid + 1;
    while(i>=0 && arr[i] == arr[j]) // skipping past equals
    {
        i--;
        j++;
    }
    bool leftsmaller = (i<0 || arr[i] < arr[j]);
    while(i>=0) // copying left side to right for case where leftsmaller is false
    {
        arr[j++] = arr[i--];
    }
    if(leftsmaller)
    {
        int carry = 1;
        int i = mid - 1;
        if(n % 2 == 1)
        {
            arr[mid] += carry;
            carry = arr[mid] / 10;
            arr[mid] = arr[mid] % 10;
            j = mid + 1;
        }
        else
        {
            j = mid;
        }
        while(i >= 0)       // propagating the carry
        {
            arr[i] += carry;
            carry = arr[i] / 10;
            arr[i] = arr[i] % 10;
            arr[j++] = arr[i--];
        }
    }
}
int main()
{
    int n;
    string k;
    cin >> n;
    cin >> k;
    int arr[n];
    for(int i = 0 ; i<n; i++)
    {
        arr[i] = (int) k[i] - 48;       // converting string to array
    }
    int all9 = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] != 9)
        {
            all9 = 1;
            break;
        }
    }
    if(all9 == 0)
    {
        int op = stoi(k);
        cout << op + 2 << endl;
        return 0;
    }
    else
    {
        nextPalin(arr,n);
    }
    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << endl;
    }
}