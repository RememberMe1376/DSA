#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a(10005);
int vs[10005] = {};
int v, e, u, x, y;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int &it : a[x])
            if (!vs[it])
            {
                vs[it] = 1;
                q.push(it);
            }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
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
        }
        BFS(u);
        cout << endl;
    }
}