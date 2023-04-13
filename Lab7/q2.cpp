#include <cmath>
#include <iostream>

using namespace std;

struct Treenode
{
    int val;
    Treenode *left;
    Treenode *right;
    Treenode(int x) : val(x), left(nullptr), right(nullptr) {} 
};

Treenode *buildTreeHelper(int *preorder, int *inorder, int n, int preStart, int inStart, int inEnd)
{
    if(preStart >= n || inStart > inEnd)
    {
        return nullptr;
    }
    Treenode *root = new Treenode(preorder[preStart]);
    int inIndex = 0;
    for(int i = inStart; i <= inEnd; i++)
    {
        if(inorder[i] == root -> val)
        {
            inIndex = i;
            break;
        }
    }
    root -> left = buildTreeHelper(preorder, inorder, n, preStart + 1, inStart, inIndex - 1);
    root -> right = buildTreeHelper(preorder, inorder, n, preStart + 1 + inIndex - inStart, inIndex + 1, inEnd);
    return root;
}

Treenode *buildTree(int *preorder, int *inorder, int n)
{
    return buildTreeHelper(preorder, inorder, n, 0, 0, n-1);
}

int findHeight(Treenode *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return 1 + max(findHeight(root -> left) , findHeight(root -> right));
}

void printCurrentLevel(Treenode *root, int level)
{
    if(root == nullptr)
    {
        for(int i = 0; i < pow(2, level - 1); i++)
        {
            cout << "-1 ";
        }
        return;
    }
    if(level == 1)
    {
        cout << root -> val << " ";
    }
    else
    {
        printCurrentLevel(root -> left, level - 1);
        printCurrentLevel(root -> right, level - 1);
    }
}

void printTree(Treenode *root)
{
    int height = findHeight(root);
    for(int i = 1; i<=height; i++)
    {
        printCurrentLevel(root, i);
    }
}

int main()
{
    int n;
    cin >> n;
    int preorder[n];
    for(int i = 0; i<n; i++)
    {
        cin >> preorder[i];
    }
    int inorder[n];
    for(int i = 0; i<n; i++)
    {
        cin >> inorder[i];
    }
    Treenode *root = buildTree(preorder, inorder, n);
    printTree(root);
    cout << endl;
    return 0;
}