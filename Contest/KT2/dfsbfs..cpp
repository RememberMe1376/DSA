#include <bits/stdc++.h>
using namespace std;
int a[10005][10005], check[10005], p[10005];
int n, s, e, tt, h = 0;
vector<int> p[10005];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    check[u] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int k : p[x])
        {
            if (!check[k])
            {
                p[k] = x;
                q.push(k);
                check[k] = true;
            }
        }
    }
}
bool vs1[10005] = {false};
int p1[10005] = {0};
void dfs(int u)
{
    vs1[u] = true;
    for (auto x : p[u])
    {
        if (!vs[x])
        {
            p[x] = u;
            dfs(x);
        }
    }
}
void in()
{
    int st = 1;
    dfs(st);
    bfs(st);
    for (int i = 2; i <= n; i++)
    {
        int en = i;
        if (!vs[en])
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> b;
            while (en != st)
            {
                b.push_back(en);
                en = p1[en];
            }
            b.push_back(st);
            reverse(b.begin(), b.end());
            for (int x : b)
                cout << x << " ";
            cout << endl;
        }
    }
}
int main()
{
}