#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, flag = 0;
        vector<int> v;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        if (binary_search(v.begin(), v.end(), k))
            cout << 1 << endl;
        else
            cout << -1 << endl;
    }
}