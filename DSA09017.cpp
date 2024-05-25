#include <bits/stdc++.h>
using namespace std;
vector<int> k[1005];
int vs[1005], flag;
void dfs(int u)
{
    vs[u] = 1;
    for (auto v : k[u])
    {
        if (vs[v])
        {
            flag = 0;
            return;
        }
        dfs(v);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            k[i].clear();
            vs[i] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            k[x].push_back(y);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vs[i] && flag)
            {
                dfs(i);
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         set<int> se;
//         for (int i = 1; i < n; i++)
//         {
//             int x, y;
//             cin >> x >> y;
//             se.insert(x);
//             se.insert(y);
//         }
//         if (se.size() != n)
//             cout << "NO\n";
//         else
//             cout << "YES\n";
//     }
// }