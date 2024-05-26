#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, d;
        cin >> s >> d;
        if (d * 9 < s)
        {
            cout << "-1\n";
            continue;
        }
        int a[d] = {};
        a[0] = 1;
        int req = s - 1;
        int i = d - 1;
        while (req >= 9)
        {
            a[i] = 9;
            req -= 9;
            i--;
        }
        a[i] += req;
        for (auto it : a)
            cout << it;
        cout << endl;
    }
}