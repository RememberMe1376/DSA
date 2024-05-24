#include <bits/stdc++.h>
using namespace std;

int v, e, x, y;
vector<int> k[1005];
int vs[1005] = {};

void BFS(int u)
{
    queue<int> q;
    vs[u] = 1;
    q.push(u);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto v : k[x])
        {
            if (!vs[v])
            {
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
        cin >> v >> e;
        for (int i = 0; i <= v; i++)
            k[i].clear();
        while (e--)
        {
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
        }
        memset(vs, 0, sizeof vs);
        int cnt = 0;
        for (int i = 1; i <= v; i++)
        {
            if (!vs[i])
            {
                cnt++;
                BFS(i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
