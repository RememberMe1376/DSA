#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int vs[1005] = {};
int v, e, x, y;
void DFS(int u)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
            DFS(v);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int flag = 1;
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
        }
        for (int i = 1; i <= v; i++)
        {
            memset(vs, 0, sizeof vs);
            DFS(i);
            for (int j = 1; j <= v; j++)
            {
                if (!vs[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}