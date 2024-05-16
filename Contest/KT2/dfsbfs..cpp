#include <bits/stdc++.h>
using namespace std;
int a[10005][10005], check[10005], p[10005];
int n, s, e, tt, h = 0;
vector<int> ke[10005];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    check[u] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int k : ke[x])
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
    for (auto x : ke[u])
    {
        if (!vs1[x])
        {
            p1[x] = u;
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
        if (!vs1[en])
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
        memset(check, 0, sizeof check);
        memset(p, 0, sizeof p);
        int en1 = i;
        bfs(en1);
        if (check[1])
        {
            vector<int> b;
            int en = 1;
            while (en != en1)
            {
                b.push_back(en);
                en = p[en];
            }
            b.push_back(en1);
            reverse(b.begin(), b.end());
            for (int it : b)
                cout << it << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}
int main()
{
    cin >> n >> tt;
    for (int i = 0; i <= n; i++)
        ke[i].clear();
    memset(a, 0, sizeof a);
    memset(check, 0, sizeof check);
    memset(p, 0, sizeof p);
    while (tt--)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    in();
}