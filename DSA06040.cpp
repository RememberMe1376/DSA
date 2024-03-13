#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<long long> v;
        int n, m, k;
        cin >> n >> m >> k;
        long long a[n], b[m], c[k];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < k; i++)
            cin >> c[i];
        int x = 0, y = 0, z = 0;
        while (x < n && y < m && z < k)
        {
            if (a[x] == b[y] && b[y] == c[z])
            {
                v.push_back(a[x]);
                x++;
                y++;
                z++;
            }
            else if (a[x] < b[y])
                x++;
            else if (b[y] < c[z])
                y++;
            else
                z++;
        }
        if (v.size() == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
        }
    }
}