#include <bits/stdc++.h>
using namespace std;
int n, a[20];
string s;
vector<int> v1;
vector<string> v2;
vector<vector<int>> res;
void solve(int x)
{
    for (int i = x + 1; i <= n; i++)
    {
        if (a[i] > a[x])
        {
            v1.push_back(a[i]);
            if (v1.size() > 1)
                res.push_back(v1);
            solve(i);
            v1.pop_back();
        }
    }
}
int main()
{
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve(0);
    for (int i = 0; i < res.size(); i++)
    {
        s = "";
        for (int j = 0; j < res[i].size(); j++)
        {
            s += to_string(res[i][j]);
            s += " ";
        }
        v2.push_back(s);
    }
    sort(v2.begin(), v2.end());
    for (auto i : v2)
        cout << i << endl;
}