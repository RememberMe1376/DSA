#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int n;
void solve(string s, int x, int y, int z)
{
    if (s.size() <= n)
    {
        if (x && y && z && x <= y && y <= z)
            v.push_back(s);
        if (s.size() == n)
            return;
    }
    solve(s + 'A', x + 1, y, z);
    solve(s + 'B', x, y + 1, z);
    solve(s + 'C', x, y, z + 1);
}
bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a <= b;
    else
        return a.size() < b.size();
}
int main()
{
    cin >> n;
    solve("", 0, 0, 0);
    sort(v.begin(), v.end(), cmp);
    for (auto it : v)
        cout << it << endl;
}