#include <bits/stdc++.h>
using namespace std;
vector<int> k[100005];
int vs[100005] = {};
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
            k[y].push_back(x);
        }
        DFS(1);
        for (int i = 2; i <= v; i++)
        {
            if (!vs[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}