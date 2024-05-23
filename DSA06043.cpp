#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k = 0, s = 0, res = -1;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (k * 2 + a[i] == s)
            {
                res = i + 1;
                break;
            }
            k += a[i];
        }
        cout << res << endl;
    }
}