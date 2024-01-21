#include <bits/stdc++.h>
using namespace std;
int prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int flag = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (prime(i))
            {
                if (!prime(s[i] - '0'))
                {
                    flag = 1;
                    break;
                }
            }
            else
            {
                if (prime(s[i] - '0'))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}