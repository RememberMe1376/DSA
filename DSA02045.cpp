#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> res;
map<string, int> m;
void Try(int i, string a)
{
    if (a != " " && m[a] == 0)
    {
        res.push_back(a);
        m[a]++;
    }
    if (i == n)
        return;
    Try(i + 1, a + s[i]);
    Try(i + 1, a);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        res.clear();
        m.clear();
        cin >> n >> s;
        Try(0, "");
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}