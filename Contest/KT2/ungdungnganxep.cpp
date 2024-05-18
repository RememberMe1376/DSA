#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, res = 0;
    cin >> n;
    stack<int> st;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        while (!st.empty() && a > st.top())
        {
            mp[st.top()]--;
            st.pop();
            res++;
        }
        if (!st.empty())
        {
            if (a == st.top())
                res += mp[a] + (st.size() > mp[a]);
            else
                res++;
        }
        st.push(a);
        mp[a]++;
    }
    cout << res;
}