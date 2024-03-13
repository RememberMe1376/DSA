#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, res = 0;
    cin >> n;
    vector<int> v(n + 5), a(n + 5, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        a[v[i]] = a[v[i] - 1] + 1;
        res = max(res, a[v[i]]);
    }
    cout << n - res;
}