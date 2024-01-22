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
        vector<int> v;
        n += m;
        while (n--)
        {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
}