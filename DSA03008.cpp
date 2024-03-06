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
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].second;
        for (int i = 0; i < n; i++)
            cin >> p[i].first;
        sort(p, p + n);
        int x = p[0].first, res = 1;
        for (int i = 1; i < n; i++)
        {
            if (p[i].second >= x)
            {
                res++;
                x = p[i].first;
            }
        }
        cout << res << endl;
    }
}