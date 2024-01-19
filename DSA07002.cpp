#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    string s;
    stack<int> st;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            cin >> n;
            st.push(n);
        }
        else if (s == "POP")
        {
            if (!st.empty())
                st.pop();
        }
        else if (s == "PRINT")
        {
            if (!st.empty())
            {
                cout << st.top() << endl;
            }
            else
                cout << "NONE" << endl;
        }
    }
}