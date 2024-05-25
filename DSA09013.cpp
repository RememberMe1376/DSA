#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int vs[1005];
int v, e, x, y;
vector<pair<int, int>> ls;
void dfs(int u)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
            dfs(v);
    }
}

void dfs2(int u, int s, int t)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if ((u == s && v == t) || (u == t && v == s))
            continue;
        if (!vs[v])
            dfs2(v, s, t);
    }
}
void solve()
{
    int res = 0;
    int lt = 0;
    memset(vs, 0, sizeof(vs));
    for (int i = 1; i <= v; i++)
    {
        if (!vs[i])
        {
            ++lt;
            dfs(i);
        }
    }
    for (auto it : ls)
    {
        int x = it.first;
        int y = it.second;
        memset(vs, 0, sizeof(vs));
        int cnt = 0;
        for (int j = 1; j <= v; j++)
        {
            if (!vs[j])
            {
                cnt++;
                dfs2(j, x, y);
            }
        }
        if (cnt > lt)
            cout << x << " " << y << " ";
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
        ls.clear();
        while (e--)
        {
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
            ls.push_back({x, y});
        }
        solve();
        cout << endl;
    }
}