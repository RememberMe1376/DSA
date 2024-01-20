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
        int n, flag = 0;
        cin >> n;
        for (int i = 2; i <= n / 2; i++)
        {
            if (prime(i) && prime(n - i))
            {
                flag = 1;
                cout << i << " " << n - i << endl;
                break;
            }
        }
        if (flag == 0)
            cout << -1 << endl;
    }
}