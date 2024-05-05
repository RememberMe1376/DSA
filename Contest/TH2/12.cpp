#include <bits/stdc++.h>
using namespace std;
int r[100000];
int find(int n)
{
    if (r[n] != n)
        r[n] = find(r[n]);
    return r[n];
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 100000; i++)
        r[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        int rA = find(a);
        int rB = find(b);
        if (x == 1)
        {
            if (rA != rB)
                r[rA] = rB;
        }
        else
        {
            if (rA == rB)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
}