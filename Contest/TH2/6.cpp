#include <bits/stdc++.h>
using namespace std;
bool doixung(string s)
{
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return tmp == s;
}
int main()
{

    int t;
    cin >> t;

    queue<string> q;
    q.push("6");
    q.push("8");

    vector<string> res;

    int lim = 26;
    int m = 13;

    while (q.front().size() < m)
    {
        string cur = q.front();
        q.pop();
        string a = cur + "6";
        string b = cur + "8";
        res.push_back(a);
        res.push_back(b);
        q.push(a);
        q.push(b);
    }
    vector<string> ans;

    for (int i = 0; i < res.size(); i++)
    {
        if (doixung(res[i]) && res[i].size() % 2 == 0)
            ans.push_back(res[i]);
        if (res[i].size() * 2 > m && res[i].size() * 2 <= lim)
        {
            string sr = res[i];
            reverse(sr.begin(), sr.end());
            ans.push_back(res[i] + sr);
        }
        if (ans.size() >= 10000)
            break;
    }

    sort(ans.begin(), ans.end(), [](string a, string b)
         { return (a.length() < b.length()) || (a.length() == b.length() && a < b); });

    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";

        cout << endl;
    }
    return 0;
}
