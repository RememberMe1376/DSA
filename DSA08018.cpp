#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int check(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '6' && s[i] != '8')
            return 0;
    }
    return 1;
}
bool cmp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
void sinh(int n)
{
    string s;
    for (int i = 0; i < n; i++)
        s += '6';
    while (1)
    {
        if (check(s))
            v.push_back(s);
        int flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '6')
            {
                flag = 1;
                s[i] = '8';
                for (int j = i + 1; j < n; j++)
                    s[j] = '6';
                break;
            }
        }
        if (flag == 0)
            break;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        v.clear();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            sinh(i);
        sort(v.begin(), v.end(), cmp);
        cout << v.size() << endl;
        for (auto it : v)
            cout << it << " ";
        cout << endl;
    }
}