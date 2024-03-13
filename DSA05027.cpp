#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, v;
        cin >> n >> v;
        int a[n + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        int x[n + 1][v + 1];
        memset(x, 0, sizeof(x));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                x[i][j] = x[i - 1][j];
                if (j >= a[i])
                    x[i][j] = max(x[i][j], x[i - 1][j - a[i]] + b[i]);
            }
        }
        cout << x[n][v] << endl;
    }
}