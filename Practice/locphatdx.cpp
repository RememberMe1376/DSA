#include <bits/stdc++.h>
using namespace std;
void in(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    cout << s << t << " ";
}
void xuly(int n)
{
    queue<string> q;
    q.push("6");
    q.push("8");
    while (n--)
    {
        string s = q.front();
        q.pop();
        in(s);
        q.push(s + "6");
        q.push(s + "8");
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        xuly(n);
        cout << endl;
    }
}