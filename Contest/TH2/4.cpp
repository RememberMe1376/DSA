#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    stack<int> st;
    cin >> n >> q;
    int x[1005];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    int res[1005];
    res[n - 1] = -1;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (x[i] < x[st.top()] && st.size())
        {
            res[i] = st.top();
            st.push(i);
        }
        else
        {
            while (st.size() && x[i] >= x[st.top()])
                st.pop();
            if (!st.empty())
                res[i] = st.top();
            else
                res[i] = -1;
            st.push(i);
        }
    }
    while (q--)
    {
        int a;
        cin >> a;
        a--;
        int cnt = 0;
        while (a != -1)
        {
            a = res[a];
            cnt++;
        }
        cout << cnt - 1 << endl;
    }
}