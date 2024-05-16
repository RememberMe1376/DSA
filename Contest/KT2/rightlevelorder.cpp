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
        left = right = nullptr;
    }
};

node *insert_node(node *root, int u)
{
    if (root == NULL)
        root = new node(u);
    else
    {
        if (u < root->data)
            root->left = insert_node(root->left, u);
        else
            root->right = insert_node(root->right, u);
    }
    return root;
}

void rightlvorder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    vector<vector<int>> lv;
    q.push(root);
    while (!q.empty())
    {
        int nodeCount = q.size();
        vector<int> lvVal;
        while (nodeCount > 0)
        {
            node *tmp = q.front();
            q.pop();
            lvVal.push_back(tmp->data);
            if (tmp->left != NULL)
                q.push(tmp->left);
            if (tmp->right != NULL)
                q.push(tmp->right);
            nodeCount--;
        }
        lv.push_back(lvVal);
    }
    for (int i = 0; i < lv.size(); i++)
    {
        for (int j = lv[i].size() - 1; j >= 0; j--)
            cout << lv[i][j] << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        node *root = NULL;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            root = insert_node(root, x);
        }
        rightlvorder(root);
        cout << endl;
    }
    return 0;
}
