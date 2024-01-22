#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, m1 = -1e9, m2 = 1e9;
        cin >> n >> m;
        while (n--)
        {
            cin >> x;
            m1 = max(m1, x);
        }
        while (m--)
        {
            cin >> x;
            m2 = min(m2, x);
        }
        cout << (long long)m1 * m2 << endl;
    }
}