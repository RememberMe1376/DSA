#include <bits/stdc++.h>
using namespace std;
int deg1[1005] = {}, deg2[1005] = {};
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
            deg1[x]++;
            deg2[y]++;
        }
        int cnt = 0, flag = 1;
        for (int i = 1; i <= v; i++)
        {
            if (abs(deg1[y] - deg2[i]) == 1)
                cnt++;
            if (cnt > 2 || abs(deg1[i] - deg2[i]) > 1 || !deg1[i] || !deg2[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        memset(deg1, 0, sizeof(deg1));
        memset(deg2, 0, sizeof(deg2));
    }
}