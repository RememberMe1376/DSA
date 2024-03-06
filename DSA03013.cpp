#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;
        int a[30] = {}, x = 0;
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'A']++;
        for (int i = 0; i < 30; i++)
            x = max(x, a[i]);
        if (x * k > s.size() + 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
}