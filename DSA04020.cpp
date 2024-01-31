#include <bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int k, int l, int r)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == k)
            return m;
        else if (a[m] < k)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x = binarySearch(a, k, 0, n - 1);
        if (x == -1)
            cout << "NO\n";
        else
            cout << x + 1 << endl;
    }
}