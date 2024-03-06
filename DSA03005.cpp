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
        int a[n], x1 = 0, x2 = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        k = min(k, n - k);
        for (int i = 0; i < k; i++)
            x1 += a[i];
        for (int i = k; i < n; i++)
            x2 += a[i];
        cout << x2 - x1 << endl;
    }
}