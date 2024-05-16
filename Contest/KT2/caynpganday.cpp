#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

node *build_tree(vector<int> &arr, int n)
{
    if (n == 0)
        return NULL;
    node *root = new node(arr[0]);
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n)
    {
        node *current = q.front();
        q.pop();
        current->left = new node(arr[i++]);
        q.push(current->left);
        if (i < n)
        {
            current->right = new node(arr[i++]);
            q.push(current->right);
        }
        return root;
    }
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        node *root = build_tree(arr, n);
        inorder(root);
        cout << endl;
    }
    return 0;
}
