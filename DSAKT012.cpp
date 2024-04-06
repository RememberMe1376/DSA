#include <bits/stdc++.h>
using namespace std;
int n, k, a[35], b[35], ss, ans, ok;
void Try(int x)
{
    for (int i = b[x - 1] + 1; i <= n; i++)
    {
        b[x] = i;
        if (x == k)
        {
            int s = 0;
            for (int j = 1; j <= k; j++)
                s += a[b[j]];
            if (s == ss)
            {
                ok = 1;
                ans = k;
                return;
            }
        }
        else
            Try(x + 1);
    }
}
int main()
{
    a[0] = ok = 0;
    ans = 50;
    cin >> n >> ss;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        k = i;
        Try(1);
        if (ok == 1)
            break;
    }
    if (ok == 0)
        cout << -1;
    else
        cout << ans;
}