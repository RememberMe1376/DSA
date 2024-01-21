#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x = 0;
    string s;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s[1] == '+')
            x++;
        else
            x--;
    }
    cout << x;
}