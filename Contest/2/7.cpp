#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<long long, long long>> v(n);
        for (pair<long long, long long> &it : v)
            cin >> it.first >> it.second;
        long long x[n][2];
        x[0][1] = v[0].second;
        x[0][0] = 0;
        for (int i = 1; i < n; ++i)
        {
            if (v[i].first == v[i - 1].first)
            {
                x[i][1] = min(x[i - 1][0], x[i - 1][1] + v[i].second);
                x[i][0] = x[i - 1][1];
            }
            else
            {
                x[i][0] = min(x[i - 1][0], x[i - 1][1]);
                x[i][1] = min(x[i - 1][0], x[i - 1][1] + v[i].second);
            }
        }
        cout << min(x[n - 1][0], x[n - 1][1]) << endl;
    }
}