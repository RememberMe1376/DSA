#include <bits/stdc++.h>
using namespace std;
void solve(int a, int b, int c)
{
    if (b * c > (b - b / 7) * a) // trừ ngày cn
        cout << -1 << endl;
    else
    {
        for (int i = 1; i <= b - b / 7; i++)
        {
            if (a * i >= b * c)
            {
                cout << i << endl;
                break;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;
        solve(n, s, m);
    }
}