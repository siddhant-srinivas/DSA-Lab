#include <iostream>
#include <stack>
using namespace std;

struct Treenode
{
    int val;
    Treenode * left;
    Treenode * right;
    Treenode(): val(0), left(nullptr), right(nullptr) {}
    Treenode(int x): val(x), left(nullptr), right(nullptr) {}
    Treenode(int x, Treenode * left, Treenode * right): val(x), left(left), right(right) {}
};

Treenode *createTree(int arr[], int n, int i)
{
    if(i >= n)
    {
        return nullptr;
    }
    Treenode * root = new Treenode(arr[i]);
    root -> left = arr[2 * i + 1] == -1 ? nullptr : createTree(arr, n, 2 * i + 1);
    root -> right = arr[2 * i + 2] == -1 ? nullptr : createTree(arr, n, 2 * i + 2);
    return root;
}

int kth_greatest(Treenode * root, int k)
{
    int count = 0, elem = 0;
    Treenode * curr = root;
    stack<Treenode *> stk;
    while(curr != nullptr || !stk.empty())
    {
        while(curr != nullptr)
        {
            stk.push(curr);
            curr = curr -> right;
        }
        curr = stk.top();
        stk.pop();
        elem = curr -> val;
        count ++;
        if(count == k)
        {
            return elem;
        }
        curr = curr -> left;
    }
    return -1;
}