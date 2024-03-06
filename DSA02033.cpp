#include <bits/stdc++.h>
using namespace std;
int n, a[100];
void check(string s)
{
    int x = s.size();
    if (x == n)
        cout << s << endl;
    for (int i = 1; i <= n; i++)
    {
        if (x == 0 || !a[i] && abs(s[x - 1] - '0' - i) != 1)
        {
            a[i] = 1;
            check(s + to_string(i));
            a[i] = 0;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        check("");
    }
}