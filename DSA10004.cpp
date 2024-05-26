#include <bits/stdc++.h>
using namespace std;
int deg[1005] = {};
int v, e, x, y;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v >> e;
        while (e--)
        {
            cin >> x >> y;
            deg[x]++;
            deg[y]++;
        }
        int cnt = 0;
        for (int i = 1; i <= v; i++)
        {
            if (deg[i] % 2 == 1)
                cnt++;
        }
        if (!cnt)
            cout << 2 << endl;
        else if (cnt == 2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        memset(deg, 0, sizeof(deg));
    }
}