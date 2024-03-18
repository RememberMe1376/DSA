#include <bits/stdc++.h>
using namespace std;
string skip0(string s)
{
    string x;
    while (s[0] == '0' && s.size() > 1)
        s.erase(0, 1);
    x = s;
    return x;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << skip0(s) << endl;
        while (next_permutation(s.begin(), s.end()))
        {
            cout << skip0(s) << endl;
        }
    }
}