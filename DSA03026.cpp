#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, s;
    cin >> n >> s;
    if (9 * n < s || s < 1)
    {
        cout << "-1 -1";
        return 0;
    }
    int a[n], b[n];
    for (int &i : b)
        i = 9;
    for (int &i : a)
        i = 0;
    a[0] = 1;

    a[0] = 1;
    int req = s - 1;
    int i = n - 1;
    while (req >= 9)
    {
        req -= 9;
        a[i] = 9;
        i--;
    }
    a[i] += req;

    req = 9 * n - s;
    i = n - 1;
    while (req > 9)
    {
        req -= 9;
        b[i] = 0;
        i--;
    }
    b[i] -= req;
    for (auto it : a)
        cout << it;
    cout << " ";
    for (auto it : b)
        cout << it;
}