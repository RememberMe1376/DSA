#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check(string a, int n, int k)
{
    int cnt = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 'A')
            cnt++;
        else
            cnt = 0;
        if (cnt > k)
            return false;
        if (cnt == k)
            res++;
    }
    return res == 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string a;
    queue<string> q;
    for (int i = 0; i < n; i++)
        a += 'A';
    while (1)
    {
        if (check(a, n, k))
            q.push(a);
        int ok = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 'A')
            {
                ok = 1;
                a[i] = 'B';
                for (int j = i + 1; j < n; j++)
                    a[j] = 'A';
                break;
            }
        }
        if (ok == 0)
            break;
    }
    cout << q.size() << endl;
    while (q.size())
    {
        cout << q.front() << endl;
        q.pop();
    }
}