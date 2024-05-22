#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        if (s.size() % 2 == 1)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' && !st.empty())
            {
                if (st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        int x = st.size(), k = 0;
        while (!st.empty() && st.top() == '(')
        {
            st.pop();
            k++;
        }
        cout << (x / 2 + k % 2) << endl;
    }
}