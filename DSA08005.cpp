#include <bits/stdc++.h>
using namespace std;
string binary(int n)
{
    stack<int> q;
    string s = "";
    while (n != 0)
    {
        q.push(n % 2);
        n /= 2;
    }
    while (!q.empty())
    {
        s += to_string(q.top());
        q.pop();
    }
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cout << binary(i) << " ";
        cout << endl;
    }
}