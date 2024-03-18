#include <bits/stdc++.h>
using namespace std;
string reverse(string s)
{
    string x(s.rbegin(), s.rend());
    return s + x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        queue<string> q;
        q.push("");
        vector<string> ans;
        while (!q.empty())
        {
            string x = q.front();
            q.pop();
            if (x.length() * 2 > n)
                break;
            if (x != "")
                ans.push_back(reverse(x));
            q.push(x + '0');
            q.push(x + '1');
        }
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
}