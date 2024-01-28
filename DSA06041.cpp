#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, max = 0;
        map<int, int> mp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            mp[x]++;
            if (mp[x] > max)
                max = mp[x];
        }
        if (max > n / 2)
        {
            for (auto it : mp)
            {
                if (it.second == max)
                {
                    cout << it.first << endl;
                    break;
                }
            }
        }
        else
            cout << "NO\n";
    }
}