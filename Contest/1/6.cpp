#include <bits/stdc++.h>
using namespace std;
int nt(int a)
{
    int m = 0;
    for (int i = 2; i <= sqrt(a); i++)
    {
        while (a % i == 0)
        {
            m = i;
            a /= i;
        }
    }
    if (a > 1)
        m = a;
    return m;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, sum = 0;
        cin >> l >> r;
        for (int i = l; i <= r; i++)
            sum += nt(i);
        cout << sum << endl;
    }
}