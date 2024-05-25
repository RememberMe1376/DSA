#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, x, y;
vector<int> k[100005];
int vs[100005];

int dfs(int u)
{
    cnt++;
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
        {
            dfs(v);
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            k[i].clear();
            vs[i] = 0;
        }
        while (m--)
        {
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
        }
        int res = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!vs[i])
            {
                cnt = 0;
                res = max(res, dfs(i));
            }
        }
        cout << res << endl;
    }
}