#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int parent[1005];

void make_set(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void union_sets(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

bool hasCycle(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        make_set(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int u : adj[i])
        {
            int x = find(i);
            int y = find(u);
            if (x == y)
                return true;
            union_sets(x, y);
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
        {
            adj[i].clear();
        }
        for (int i = 0; i < e; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (hasCycle(v))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
