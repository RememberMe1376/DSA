#include <bits/stdc++.h>
using namespace std;
int thuannghich(string s)
{
    int n = s.size();
    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
            return 0;
    }
    return 1;
}
void sinh(int n)
{
    string a;
    for (int i = 0; i < n; i++)
        a += '0';
    while (1)
    {
        if (thuannghich(a))
        {
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        int check = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == '0')
            {
                check = 1;
                a[i] = '1';
                for (int j = i + 1; j < n; j++)
                    a[j] = '0';
                break;
            }
        }
        if (check == 0)
            break;
    }
}
int main()
{
    int n;
    cin >> n;
    sinh(n);
}