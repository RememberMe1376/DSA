#include <bits/stdc++.h>
using namespace std;
void solve(string s)
{
    string res = "";
    int cur = 0;
    for (char c : s)
    {
        if (c == '-')
        {
            if (cur > 0)
                res.erase(cur - 1, 1);
            cur--;
        }
        else if (c == '<')
        {
            if (cur > 0)
                cur--;
        }
        else if (c == '>')
        {
            if (cur < res.size())
                cur++;
        }
        else
        {
            res.insert(cur, 1, c);
            cur++;
        }
    }
    cout << res;
}
int main()
{
    string s;
    cin >> s;
    solve(s);
}