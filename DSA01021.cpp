#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        map<int, int> mp;
        int n, k, check = 0;
        cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                check = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            if (mp[a[i]] == 0)
                cnt++;
        }
        if (check == 0)
            cnt = k;
        cout << cnt << endl;
    }
}