#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int vs[1005];
int par[1005];
int v, e, x, y;
bool dfs(int u)
{
    // 0: chua tham
    // 1: chua xong
    // 2: da xong
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (vs[v] == 0)
        {
            par[v] = u;
            if (dfs(v))
                return true;
        }
        else if (vs[v] == 1)
            return true;
    }
    vs[u] = 2;
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