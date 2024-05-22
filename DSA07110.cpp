#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int check = 1;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                {
                    check = 0;
                    break;
                }
            }
            else if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                {
                    check = 0;
                    break;
                }
            }
            else
            {
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                {
                    check = 0;
                    break;
                }
            }
        }
        if (!st.empty())
            check = 0;
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}