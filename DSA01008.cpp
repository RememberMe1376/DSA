#include <bits/stdc++.h>
using namespace std;
int check(string s, int x)
{
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    if (cnt == x)
        return 1;
    return 0;
}
void sinh(int n, int x)
{
    string a;
    for (int i = 0; i < n; i++)
        a += '0';
    while (1)
    {
        if (check(a, x))
        {
            for (int i = 0; i < n; i++)
                cout << a[i];
            cout << endl;
        }
        int flag = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == '0')
            {
                flag = 1;
                a[i] = '1';
                for (int j = i + 1; j < n; j++)
                    a[j] = '0';
                break;
            }
        }
        if (flag == 0)
            break;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        sinh(n, k);
        cout << endl;
    }
}