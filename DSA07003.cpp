#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        int flag = 0;
        getline(cin, s);
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                st.push(s[i]);
            if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    flag = 1;
                    break;
                }
                while (!st.empty() && st.top() != '(')
                    st.pop();
                st.pop();
            }
        }
        if (flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}