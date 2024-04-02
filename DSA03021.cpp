#include <bits/stdc++.h>
using namespace std;
int a[1000], b[1000];
int n, res = 0;
int check(int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] / x == a[i] / (x + 1))
            return 0;
    return 1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = b[0]; i >= 0; i--)
    {
        if (check(i))
        {
            for (int j = 0; j < n; j++)
                res += a[j] / (i + 1) + 1;
            break;
        }
    }
    cout << res;
}