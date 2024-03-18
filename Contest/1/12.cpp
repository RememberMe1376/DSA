#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 9;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    long long a[n + 1], b[m + 1], f[n + 1][m + 1][k + 1] = {};
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] > b[j])
                f[i][j][1] = 1;
            else
                f[i][j][1] = 0;
        }
    }
    for (int x = 1; x <= k; x++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                f[i][j][x] += f[i - 1][j][x] + f[i][j - 1][x] - f[i - 1][j - 1][x];
                if (a[i] > b[j])
                    f[i][j][x] += f[i - 1][j - 1][x - 1];
                f[i][j][x] %= mod;
            }
        }
    }
    while (f[n][m][k] < 0)
        f[n][m][k] += mod;
    cout << f[n][m][k];
}