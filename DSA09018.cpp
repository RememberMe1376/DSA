#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int vs[1005];
int v, e, x, y;
void dfs(int u)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
            dfs(v);
    }
}

void solve()
{
    for (int i = 1; i <= v; i++)
    {
        memset(vs, 0, sizeof(vs));
        vs[i] = 1;
        int cnt = 0;
        for (int j = 1; j <= v; j++)
        {
            if (!vs[j])
            {
                cnt++;
                dfs(j);
            }
        }
        if (cnt > 1)
            cout << i << " ";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
        {
            k[i].clear();
            vs[i] = 0;
        }
        while (e--)
        {
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
        }
        solve();
        cout << endl;
    }
}