#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v, e, x, y;
vector<int> k[1005];
int vs[1005] = {};

void DFS(int u)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (!vs[v])
            DFS(v);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
            k[i].clear();
        while (e--)
        {
            cin >> x >> y;
            k[x].push_back(y);
            k[y].push_back(x);
        }
        memset(vs, 0, sizeof vs);
        int cnt = 0;
        for (int i = 1; i <= v; i++)
        {
            if (!vs[i])
            {
                cnt++;
                DFS(i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
