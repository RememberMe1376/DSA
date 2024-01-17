#include <bits/stdc++.h>
using namespace std;
int haha(string s)
{
    int n = s.size();
    if (s[0] != 'H' || s[n - 1] != 'A')
        return 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'H' && s[i + 1] == 'H')
            return 0;
    }
    return 1;
}
void sinh(int n)
{
    vector<string> v;
    string a;
    for (int i = 0; i < n; i++)
        a += 'H';
    while (1)
    {
        if (haha(a))
        {
            v.push_back(a);
        }
        int check = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 'H')
            {
                check = 1;
                a[i] = 'A';
                for (int j = i + 1; j < n; j++)
                    a[j] = 'H';
                break;
            }
        }
        if (check == 0)
            break;
    }
    sort(v.begin(), v.end());
    for (auto x : v)
        cout << x << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        sinh(n);
        cout << endl;
    }
}