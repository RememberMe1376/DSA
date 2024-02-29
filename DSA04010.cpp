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
        int a, res = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            sum += a;
            res = max(res, sum);
            if (sum < 0)
                sum = 0;
        }
        cout << res << endl;
    }
}