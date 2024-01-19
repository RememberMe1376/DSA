#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "pop")
        {
            if (!st.empty())
                st.pop();
        }
        else if (s == "show")
        {
            if (!st.empty())
            {
                stack<int> z;
                while (!st.empty())
                {
                    z.push(st.top());
                    st.pop();
                }
                while (!z.empty())
                {
                    cout << z.top() << " ";
                    st.push(z.top());
                    z.pop();
                }
                cout << endl;
            }
            else
                cout << "empty" << endl;
        }
    }
}