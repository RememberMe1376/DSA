#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int x, y, w;
};

// Su dung Prim
//  vector<pair<int, int>> k;
//  int used[1005];

// void input()
// {
//     cin >> n >> m;
//     while (e--)
//     {
//         int x, y, w;
//         cin >> x >> y >> w;
//         k[x].push_back({y, w});
//         k[y].push_back({x, w});
//     }
//     memset(used, 0, sizeof(used));
// }

// void prim(int u)
// {
//     vector<Edge> mst;
//     int d = 0;
//     used[u] = 1;
//     while (mst.size() < n - 1)
//     {
//         int min_w = 1e9, X, Y;
//         for (int i = 1; i <= v; i++)
//         {
//             if (used[i])
//             {
//                 for (auto it : k[i])
//                 {
//                     int j = it.first;
//                     int ts = it.second;
//                     if (!used[j] && ts < min_w)
//                     {
//                         min_w = ts;
//                         X = j;
//                         Y = i;
//                     }
//                 }
//             }
//         }
//         mst.push_back(X, Y, min_w);
//         d += min_w;
//         used[X] = 1;
//     }
//     cout << d << endl;
// }

int t, n, m;
int parent[1005];
int sz[1005];
vector<Edge> E;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    else
        return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void Kruskal()
{
    vector<Edge> mst;
    sort(E.begin(), E.end(), cmp);
    int d = 0;
    for (auto e : E)
    {
        if (mst.size() == n - 1)
            break;
        if (Union(e.x, e.y))
        {
            mst.push_back(e);
            d += e.w;
        }
    }
    cout << d << endl;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        init();
        for (int i = 0; i < m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            E.push_back({x, y, w});
        }
        Kruskal();
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));
        E.clear();
    }
    return 0;
}