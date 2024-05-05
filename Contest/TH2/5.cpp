#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n;
vector<string> v;
ll res(ll a, ll b, string c)
{
    if (c == "+")
        return a + b;
    else if (c == "-")
        return a - b;
    else if (c == "*")
        return a * b;
    else
        return a / b;
}
ll num(string s)
{
    ll x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        x = x * 10 + (s[i] - '0');
    }
    return x;
}
void tiento()
{
    stack<ll> st;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/")
        {
            if (v[i][0] == '-')
            {
                string tmp = "";
                for (int j = 1; j < v[i].size(); j++)
                {
                    tmp += string(1, v[i][j]);
                }
                st.push(-1 * num(tmp));
            }
            else
            {
                st.push(num(v[i]));
            }
        }
        else
        {
            ll a = st.top();
            st.pop();
            ll b = st.top();
            st.pop();
            st.push(res(a, b, v[i]));
        }
    }
    cout << st.top() << endl;
}
void hauto()
{
    stack<ll> st;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/")
        {
            if (v[i][0] == '-')
            {
                string tmp = "";
                for (int j = 1; j < v[i].size(); j++)
                {
                    tmp += string(1, v[i][j]);
                }
                st.push(-1 * num(tmp));
            }
            else
            {
                st.push(num(v[i]));
            }
        }
        else
        {
            ll a = st.top();
            st.pop();
            ll b = st.top();
            st.pop();
            st.push(res(b, a, v[i]));
        }
    }
    cout << st.top() << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        if (v[0] == "+" || v[0] == "-" || v[0] == "*" || v[0] == "/")
            tiento();
        else
            hauto();
        v.clear();
    }
}