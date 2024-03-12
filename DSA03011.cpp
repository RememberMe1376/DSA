#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            q.push(a);
        }
        while (q.size() > 1)
        {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            int z = (x + y) % mod;
            sum = (sum + z) % mod;
            q.push(z);
        }
        cout << sum << endl;
    }
}