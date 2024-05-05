#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        b[i] = n - a[i];
    int l[m], r[m];
    stack<int> s1, s2, s3, s4;
    s1.push(m - 1);
    for (int i = m - 1; i >= 0; i--)
    {
        while (s1.size() && a[i] <= a[s1.top()])
            s1.pop();
        if (s1.size())
            r[i] = s1.top() - 1;
        else
            r[i] = m - 1;
        s1.push(i);
    }
    for (int i = 0; i < m; i++)
    {
        while (s2.size() && a[i] <= a[s2.top()])
            s2.pop();
        if (s2.size())
            l[i] = s2.top() + 1;
        else
            l[i] = 0;
        s2.push(i);
    }
    long long res1 = 0, res2 = 0;
    for (int i = 0; i < m; i++)
        res1 = max(res1, 1LL * a[i] * (r[i] - l[i] + 1));
    s3.push(m - 1);
    for (int i = m - 1; i >= 0; i--)
    {
        while (s3.size() && b[i] <= b[s3.top()])
            s3.pop();
        if (s3.size())
            r[i] = s3.top() - 1;
        else
            r[i] = m - 1;
        s3.push(i);
    }
    for (int i = 0; i < m; i++)
    {
        while (s4.size() && b[i] <= b[s4.top()])
            s4.pop();
        if (s4.size())
            l[i] = s4.top() + 1;
        else
            l[i] = 0;
        s4.push(i);
    }
    for (int i = 0; i < m; i++)
        res2 = max(res2, 1LL * b[i] * (r[i] - l[i] + 1));
    cout << max(res1, res2);
}