#include <bits/stdc++.h>
using namespace std;
int a, n, m, x, y;
vector<int> k[10005];
int vs[10005], cnt[10005];
vector<int> pos;
void DFS(int u)
{
    cnt[u]++;
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
            DFS(v);
    }
}
int main()
{
    cin >> a >> n >> m;
    for (int i = 0; i < a; i++)
    {
        cin >> x;
        pos.push_back(x);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        k[x].push_back(y);
    }
    for (auto it : pos)
    {
        memset(vs, 0, sizeof(vs));
        DFS(it);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == a)
            res++;
    }
    cout << res;
}