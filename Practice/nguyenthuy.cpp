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
    q.push("4");
    q.push("5");
    while (n--)
    {
        string s = q.front();
        q.pop();
        in(s);
        q.push(s + "4");
        q.push(s + "5");
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