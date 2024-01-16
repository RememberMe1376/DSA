#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k;
        cin >> n >> x;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            if (k == x)
                flag = 1;
        }
        if (flag)
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
}