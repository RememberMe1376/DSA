#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long solve(long long n, long long k)
{
    if (k == 0)
        return 1;
    long long x = solve(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return (((x * x) % mod) * n) % mod;
}
int main()
{
    while (1)
    {
        long long a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;
        cout << solve(a, b) << endl;
    }
}