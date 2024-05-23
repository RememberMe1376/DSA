#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e, x, y;
        cin >> v >> e;
        vector<vector<int>> a(v + 1);
        for (int i = 0; i < e; i++)
        {
            cin >> x >> y;
            a[x].push_back(y);
        }
        for (int i = 1; i <= v; i++)
        {
            sort(a[i].begin(), a[i].end());
            cout << i << ": ";
            for (int j = 0; j < a[i].size(); j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
}