#include <bits/stdc++.h>
using namespace std;
int solve(string a, string b)
{
    int f[a.size() + 1][b.size() + 1] = {};
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
                f[i + 1][j + 1] = f[i][j] + 1;
            else
                f[i + 1][j + 1] = max(f[i][j + 1], f[i + 1][j]);
        }
    }
    return f[a.size()][b.size()];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, v;
        cin >> s >> v;
        cout << solve(s, v) << endl;
    }
}