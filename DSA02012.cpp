#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, x;
        cin >> m >> n;
        int a[m + 1][n + 1] = {};
        a[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> x;
                a[i][j] = a[i - 1][j] + a[i][j - 1];
            }
        }
        cout << a[m][n] << endl;
    }
}