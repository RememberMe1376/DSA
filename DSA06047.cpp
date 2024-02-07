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
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        int flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long m = a[i] * a[i] + a[j] * a[j];
                long long k = sqrt(m);
                if (k * k == m && binary_search(a + j + 1, a + n, k))
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}