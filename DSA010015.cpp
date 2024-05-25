#include <bits/stdc++.h>
using namespace std;
int v, e, x, y, z;
int parent[1005], sz[1005];
struct edge
{
    int x, y, z;
    edge(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};
vector<edge> k;
void make_set()
{
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

bool cmp(edge a, edge b)
{
    return a.z < b.z;
}

void kruskal()
{
    vector<edge> mst;
    int d = 0;
    sort(k.begin(), k.end(), cmp);
    for (int i = 0; i < e; i++)
    {
        if (mst.size() == v - 1)
            break;
        edge a = k[i];
        if (Union(a.x, a.y))
        {
            mst.push_back(a);
            d += a.z;
        }
    }
    if (mst.size() == v - 1)
        cout << d << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        k.clear();
        while (e--)
        {
            cin >> x >> y >> z;
            edge m = edge(x, y, z);
            k.push_back(m);
        }
        make_set();
        kruskal();
    }
}