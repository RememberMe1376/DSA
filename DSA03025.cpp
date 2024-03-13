#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, res = 0, k = 0;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            if (v[i].first >= k)
            {
                k = v[i].second;
                res++;
            }
        }
        cout << res << endl;
    }
}