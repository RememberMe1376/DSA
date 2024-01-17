#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s = '1' + s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
                for (int j = i + 1; j < s.size(); j++)
                    s[j] = '1';
                break;
            }
        }
        for (int i = 1; i < s.size(); i++)
            cout << s[i];
        cout << endl;
    }
}