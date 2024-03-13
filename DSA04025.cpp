#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, x[2][2], y[2][2];
void nhan(long long f[2][2], long long g[2][2])
{
    long long a = (f[0][0] * g[0][0] % mod + f[0][1] * g[1][0] % mod) % mod;
    long long b = (f[0][0] * g[0][1] % mod + f[0][1] * g[1][1] % mod) % mod;
    long long c = (f[1][0] * g[0][0] % mod + f[1][1] * g[1][0] % mod) % mod;
    long long d = (f[1][0] * g[0][1] % mod + f[1][1] * g[1][1] % mod) % mod;
    x[0][0] = a;
    x[0][1] = b;
    x[1][0] = c;
    x[1][1] = d;
}
void Pow(long long f[2][2], long long n)
{
    if (n <= 1)
        return;
    Pow(f, n / 2);
    nhan(f, f);
    if (n & 1)
        nhan(f, y);
}
long long solve(long long n)
{
    x[0][0] = x[0][1] = x[1][0] = 1;
    x[1][1] = 0;
    y[0][0] = y[0][1] = y[1][0] = 1;
    y[1][1] = 0;
    Pow(x, n - 1);
    return x[0][0];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << solve(n) << endl;
    }
}