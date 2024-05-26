#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        string s;
        cin >> s;
        int cnt[256] = {};
        for (char &c : s)
            cnt[c]++;
        priority_queue<int, vector<int>> q;
        for (int it : cnt)
        {
            if (it)
                q.push(it);
        }
        while (k--)
        {
            int x = q.top();
            q.pop();
            x--;
            if (x)
                q.push(x);
        }
        long long res = 0;
        while (!q.empty())
        {
            res += pow(q.top(), 2);
            q.pop();
        }
        cout << res << endl;
    }
}