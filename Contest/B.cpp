#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long long max = 0, min = LLONG_MAX;
    while (scanf("%lld", &n) != EOF)
    {
        if (n > max)
            max = n;
        if (n < min)
            min = n;
    }
    cout << max << " " << min;
}