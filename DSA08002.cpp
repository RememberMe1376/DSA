#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> s;
        if (s[1] == 'U')
        {
            cin >> n;
            q.push(n);
        }
        else if (s[1] == 'R')
        {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << "NONE\n";
        }
        else
        {
            if (!q.empty())
                q.pop();
        }
    }
}