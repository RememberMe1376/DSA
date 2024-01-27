#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> a, b;
        queue<pair<int, int>> q;
        a.first = n;
        a.second = 0;
        q.push(a);
        while (!q.empty())
        {
            a = q.front();
            q.pop();
            if (a.first == 1)
            {
                cout << a.second << endl;
                break;
            }
            b.second = a.second + 1;
            if (a.first % 2 == 0)
            {
                b.first = a.first / 2;
                q.push(b);
            }
            if (a.first % 3 == 0)
            {
                b.first = a.first / 3;
                q.push(b);
            }
            if (a.first > 1)
            {
                b.first = a.first - 1;
                q.push(b);
            }
        }
    }
}