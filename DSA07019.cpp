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
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        stack<long long> st;
        long long ans = 0;
        long long i = 0;
        while (i < n)
        {
            if (st.empty() || a[i] >= a[st.top()])
            {
                st.push(i);
                i++;
            }
            else
            {
                long long x = st.top();
                st.pop();
                if (st.empty())
                    ans = max(ans, i * a[x]);
                else
                    ans = max(ans, a[x] * (i - st.top() - 1));
            }
        }
        while (!st.empty())
        {
            long long x = st.top();
            st.pop();
            if (st.empty())
                ans = max(ans, i * a[x]);
            else
                ans = max(ans, a[x] * (i - st.top() - 1));
        }
        cout << ans << endl;
    }
}