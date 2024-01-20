#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, s = 0;
        cin >> n >> k;
        int a[n];
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            mp[x]++;
        }
        for (auto it : mp)
        {
            if (it.first * 2 == k)
                s += it.second * (it.second - 1);
            else
                s += it.second * mp[k - it.first];
        }
        s /= 2;
        cout << s << endl;
    }
}