#include <bits/stdc++.h>
using namespace std;
string x = "+-*/";
int check(char c)
{
    for (char i : x)
        if (i == c)
            return 1;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, a;
        cin >> s;
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (check(s[i]))
            {
                a = '(' + st.top();
                st.pop();
                a += s[i];
                a = a + st.top() + ')';
                st.pop();
                st.push(a);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}