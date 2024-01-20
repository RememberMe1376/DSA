#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        map<int, int> a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a[x]++;
            c[x]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            b[x]++;
            c[x]++;
        }
        for (auto it : c)
            cout << it.first << " ";
        cout << endl;
        for (auto it : a)
        {
            if (b[it.first] > 0)
                cout << it.first << " ";
        }
        cout << endl;
    }
}