#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], mod = 1e9 + 7;
int main()
{
    a[0][0] = 1;
    for (int i = 1; i < 1005; i++)
    {
        a[i][0] = 1;
        for (int j = 1; j < 1005; j++)
            a[i][j] = (a[i - 1][j - 1] % mod + a[i - 1][j] % mod) % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << a[n][k] << endl;
    }
}