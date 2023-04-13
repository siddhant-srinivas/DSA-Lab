#include <iostream>

using namespace std;

struct Treenode
{
    int val;
    Treenode * left;
    Treenode * right;
    Treenode() : val(0), left(nullptr), right(nullptr) {}
    Treenode(int x): val(x), left(nullptr), right(nullptr) {}
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

Treenode *del(Treenode *root, int l, int r)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(root -> val < l)
    {
        return del(root -> right, l, r);
    }
    if(root -> val > r)
    {
        return del(root -> left, l, r);
    }
    root -> left = del(root -> left, l, r);
    root -> right = del(root -> right, l, r);
    return root;
}

void printTree(Treenode *root)
{
    if(root == nullptr)
    {
        return;
    }
    printTree(root -> left);
    printTree(root -> right);
    cout << root -> val << " ";
}

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    Treenode *root = createTree(arr, n, 0);
    Treenode *bst = del(root,l,r);
    printTree(bst);
    cout << endl;
    return 0;
}