#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    string x;
    vector<string> v;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    for (auto it : mp)
        v.push_back(it.first);
    n = v.size();
    v.insert(v.begin(), 1, "");
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << v[a[i]] << " ";
        cout << endl;
        int check = 0;
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
        if (check == 0)
            return 0;
    }
}