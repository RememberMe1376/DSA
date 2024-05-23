#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a(10005);
int vs[10005] = {};
int v, e, u, x, y;
void DFS(int u)
{
    cout << u << " ";
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i++)
        if (vs[a[u][i]] == 0)
            DFS(a[u][i]);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        a.clear();
        memset(vs, 0, sizeof vs);
        cin >> v >> e >> u;
        for (int i = 1; i <= v; ++i)
        {
            a[i].clear();
            vs[i] = 0;
        }
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        DFS(u);
        cout << endl;
    }
}