#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int tr[1005]; // trace
int vs[1005] = {};
int v, e, x, y, s, t;
void DFS(int u)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
        {
            tr[v] = u;
            DFS(v);
        }
    }
}

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
        {
            k[i].clear();
            vs[i] = 0;
            tr[i] = 0;
        }
        while (e--)
        {
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
        }
        int n;
        cin >> n;
        while (n--)
        {
            for (int i = 1; i <= v; i++)
            {
                vs[i] = 0;
                tr[i] = 0;
            }
            cin >> s >> t;
            DFS(s);
            if (vs[t])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}