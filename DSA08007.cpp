#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int res = 0;
        queue<string> q;
        q.push("1");
        while (!q.empty())
        {
            string x = q.front();
            q.pop();
            res++;
            string a = x + "0";
            if (a.size() > s.size() || (a.size() == s.size() && x > s))
                break;
            q.push(a);
            a = x + "1";
            if (a.size() > s.size() || (a.size() == s.size() && x > s))
                break;
            q.push(a);
        }
        cout << res + q.size() << endl;
    }
}