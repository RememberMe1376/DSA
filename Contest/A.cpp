#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long long max = 0;
    while (scanf("%lld", &n) != EOF)
    {
        if (n > max)
            max = n;
    }
    cout << max;
}