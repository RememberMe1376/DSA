#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int vs[1005];
int v, e, x, y;
int par[1005];

bool dfs(int u)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
        {
            par[v] = u;
            if (dfs(v))
                return true;
        }
        else if (v != par[u])
            return true;
    }
    return false;
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
            par[i] = 0;
        }
        while (e--)
        {
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
        }
        int flag = 0;
        for (int i = 1; i <= v; i++)
        {
            memset(par, 0, sizeof(par));
            if (!vs[i])
            {
                if (dfs(i))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}