#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, u, v;
        cin >> n >> m;
        vector<vector<int>> x(n + 1);
        while (m--)
        {
            cin >> u >> v;
            x[u].push_back(v);
            x[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < x[i].size(); j++)
                cout << x[i][j] << " ";
            cout << endl;
        }
    }
}