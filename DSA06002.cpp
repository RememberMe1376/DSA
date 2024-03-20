#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i].first = abs(a[i] - k);
            b[i].second = i;
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
            cout << a[b[i].second] << " ";
        cout << endl;
    }
}