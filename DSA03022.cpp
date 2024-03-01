#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long x;
    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    n = a.size();
    sort(a.begin(), a.end());
    long long res = max(a[0] * a[1], max(a[0] * a[1] * a[n - 1], max(a[n - 1] * a[n - 2], a[n - 1] * a[n - 2] * a[n - 3])));
    if (res > 0)
        cout << res;
    else
        cout << 0;
}