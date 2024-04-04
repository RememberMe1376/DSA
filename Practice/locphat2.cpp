#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
    queue<long long> q;
    int cnt = 0;
    q.push(6);
    set<long long> se;
    while (!q.empty())
    {
        long long k = q.front();
        if (k >= pow(10, n))
            break;
        se.insert(k);
        q.pop();
        q.push(k * 10 + 6);
        q.push(k * 10 + 8);
    }
    while (!q.empty())
        q.pop();
    q.push(8);
    while (!q.empty())
    {
        long long k = q.front();
        if (k >= pow(10, n))
            break;
        se.insert(k);
        q.pop();
        q.push(k * 10 + 6);
        q.push(k * 10 + 8);
    }
    cout << se.size() << endl;
    for (auto it : se)
        cout << it << " ";
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        solve(n);
    }
}