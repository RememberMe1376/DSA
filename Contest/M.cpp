#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
    int max = -1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            max = i;
            n /= i;
        }
    }
    if (n > 1)
        max = n;
    return max;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            sum += solve(i);
        }
        cout << sum << endl;
    }
}
