#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, cnt = 0;
        cin >> n >> x;
        int k;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (k == x)
                cnt++;
        }
        if (cnt > 0)
            cout << cnt << endl;
        else
            cout << -1 << endl;
    }
}