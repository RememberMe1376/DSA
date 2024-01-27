#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<long long> a(n + 2);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        a[n + 1] = 1e18;
        int pos = lower_bound(a.begin(), a.end() - 1, x) - a.begin();
        if (a[pos] != x)
            pos--;
        if (pos != -1)
            pos++;
        cout << pos << endl;
    }
}