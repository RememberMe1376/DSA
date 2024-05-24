#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> k;
vector<int> tr; // trace
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

void trace(int s, int t)
{
    if (!tr[t])
    {
        cout << -1;
        return;
    }
    vector<int> res;
    while (s != t)
    {
        if (!t)
        {
            cout << -1;
            return;
        }
        res.push_back(t);
        t = tr[t];
    }
    res.push_back(t);
    reverse(res.begin(), res.end());
    for (int &i : res)
        cout << i << ' ';
}
int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        cin >> v >> e >> s >> t;
        tr.resize(v + 1);
        k.resize(v + 1);
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
        }
        DFS(s);
        trace(s, t);
        cout << endl;
    }
}