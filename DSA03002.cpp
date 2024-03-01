#include <bits/stdc++.h>
using namespace std;
long long min_num(string s)
{
    long long x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '6')
            s[i] = '5';
        x = x * 10 + s[i] - '0';
    }
    return x;
}
long long max_num(string s)
{
    long long x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '5')
            s[i] = '6';
        x = x * 10 + s[i] - '0';
    }
    return x;
}
int main()
{
    string a, b;
    cin >> a >> b;
    cout << min_num(a) + min_num(b) << " " << max_num(a) + max_num(b);
}