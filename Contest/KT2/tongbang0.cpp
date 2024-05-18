#include <bits/stdc++.h>
using namespace std;
int n;
map<long long, long long> a;
int main()
{
    cin >> n;
    long long sum = 0, kq = 0, x;
    a[0]++;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum += x;
        kq += a[sum];
        a[sum]++;
    }
    cout << kq;
}
