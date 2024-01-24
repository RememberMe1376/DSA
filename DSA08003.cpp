#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> q;
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
            if (s[4] == 'F')
                q.push_front(n);
            else
                q.push_back(n);
        }
        else if (s[1] == 'R')
        {
            if (!q.empty())
            {
                if (s[5] == 'F')
                    cout << q.front() << endl;
                else
                    cout << q.back() << endl;
            }
            else
                cout << "NONE\n";
        }
        else
        {
            if (!q.empty())
            {
                if (s[3] == 'F')
                    q.pop_front();
                else
                    q.pop_back();
            }
        }
    }
}