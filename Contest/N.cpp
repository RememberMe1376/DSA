#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, x = "";
        cin >> s;
        int sum = 0;
        sort(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                sum += s[i] - '0';
            else
                x += s[i];
        }
        cout << x << sum << endl;
    }
}