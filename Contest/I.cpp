#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, a, b;
        cin >> s;
        int n = s.size();
        if (n % 2 == 1)
            cout << "INVALID\n";
        else
        {
            string l = s.substr(0, n / 2);
            string r = s.substr(n / 2);
            long long x = stoll(l);
            long long y = stoll(r);
            cout << x * y / (__gcd(x, y)) << endl;
        }
    }
}