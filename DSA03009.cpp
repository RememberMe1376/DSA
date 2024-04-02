#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, cnt = 0, res = 0;
        cin >> n;
        int check[n + 1] = {};
        vector<pair<int, int>> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> m >> a[i].second >> a[i].first;
        sort(a.begin() + 1, a.end(), greater<pair<int, int>>());
        for (int i = 1; i <= n; i++)
        {
            for (int j = min(n, a[i].second); j >= 1; j--)
            {
                if (!check[j])
                {
                    res += a[i].first;
                    cnt++;
                    check[j] = 1;
                    break;
                }
            }
        }
        cout << cnt << " " << res << endl;
    }
}