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
        int a[n + 1];
        pair<int, int> p;
        p.second = 1e9;
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (mp[a[i]] == 0)
                mp[a[i]] = i;
            else if (p.second > mp[a[i]])
            {
                p.first = a[i];
                p.second = mp[a[i]];
            }
        }
        if (p.second != 1e9)
            cout << p.first << endl;
        else
            cout << "NO\n";
    }
}