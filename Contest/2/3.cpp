#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
long long x[5005][5005];
pair<long long, long long> a[5001];
void Do()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j < a[i].first)
                x[i][j] = x[i - 1][j];
            else
                x[i][j] = max(x[i - 1][j], x[i - 1][j - a[i].first] + a[i].second);
            ans = max(ans, x[i][j]);
        }
    }
}
int main()
{
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    Do();
    cout << ans << endl;
}