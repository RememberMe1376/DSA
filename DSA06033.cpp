#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first;
            p[i].second = i;
        }
        sort(p, p + n);
        int res = -1, M = p[0].second, x = p[0].first;
        for (int i = 1; i < n; i++)
        {
            if (p[i].first > x)
                res = max(res, p[i].second - M);
            if (M > p[i].second)
            {
                M = p[i].second;
                x = p[i].first;
            }
        }
        cout << res << endl;
    }
}