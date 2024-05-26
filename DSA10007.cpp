#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int vs[1005];
vector<pair<int, int>> res;

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (auto v : k[u])
        {
            if (!vs[v])
            {
                res.push_back({u, v});
                vs[v] = 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u;
        cin >> n >> m >> u;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
        }
        BFS(u);
        if (res.size() == n - 1)
        {
            for (auto it : res)
                cout << it.first << " " << it.second << endl;
        }
        else
            cout << -1 << endl;
        for (int i = 1; i <= n; i++)
        {
            k[i].clear();
            vs[i] = 0;
        }
        res.clear();
    }
}