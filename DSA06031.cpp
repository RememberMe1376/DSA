#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        deque<int> q;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            while (q.size() && a[q.back()] <= a[i])
                q.pop_back();
            q.push_back(i);
            if (q.front() + k <= i)
                q.pop_front();
            if (i >= k - 1)
                cout << a[q.front()] << " ";
        }
        cout << endl;
    }
}