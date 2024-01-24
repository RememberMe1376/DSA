#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        queue<int> q;
        int n;
        cin >> n;
        while (n--)
        {
            int a;
            cin >> a;
            switch (a)
            {
            case 1:
                cout << q.size() << endl;
                break;
            case 2:
                if (q.empty())
                    cout << "YES\n";
                else
                    cout << "NO\n";
                break;
            case 3:
                int n;
                cin >> n;
                q.push(n);
                break;
            case 4:
                if (!q.empty())
                    q.pop();
                break;
            case 5:
                if (!q.empty())
                    cout << q.front() << endl;
                else
                    cout << -1 << endl;
                break;
            case 6:
                if (!q.empty())
                    cout << q.back() << endl;
                else
                    cout << -1 << endl;
                break;
            }
        }
    }
}