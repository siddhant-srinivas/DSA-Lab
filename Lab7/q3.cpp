#include <iostream>

using namespace std;

struct Treenode
{
    int val;
    Treenode * left;
    Treenode * right;
    Treenode() : val(0), left(nullptr), right(nullptr) {}
    Treenode(int x) : val(x), left(nullptr), right(nullptr) {}
    Treenode (int x, Treenode * left, Treenode * right) : val(x), left(left), right(right) {}
};

int tatakae(Treenode *root, int targetSum, int currentSum)
{
    if(!root)
    {
        return 0;
    }
    currentSum += root -> val;
    if(!root->left && !root->right && targetSum == currentSum)
    {
        return 1;
    }
    return tatakae(root -> left, targetSum, currentSum) + tatakae(root -> right, targetSum, currentSum);
}

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
int main()
{
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    Treenode *root = createTree(arr, n, 0);
    cout << tatakae(root,sum,0) << endl;
}