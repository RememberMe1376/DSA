#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000], b[1000] = {};
void btrack(int n)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (!b[i])
        {
            a[n] = i;
            b[i] = 1;
            if (n == s.size() - 1)
            {
                for (int i = 0; i < s.size(); i++)
                    cout << s[a[i]];
                cout << " ";
            }
            else
                btrack(n + 1);
            b[i] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        btrack(0);
        cout << endl;
    }
}