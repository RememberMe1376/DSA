#include <bits/stdc++.h>
using namespace std;
int n, k, check;
int a[1001], b[1001];
void kt()
{
    for (int i = 1; i <= k; i++)
    {
        a[i] = 1;
        b[i] = n;
    }
}
void sinh()
{
    for (int i = k; i >= 1; i--)
    {
        if (a[i] < b[i])
        {
            a[i] += 1;
            for (int j = i + 1; j <= k; j++)
            {
                a[j] = a[j - 1];
            }
            return;
        }
        if (i == 1)
        {
            check = 0;
            return;
        }
    }
}
int main()
{
    cin >> n >> k;
    check = 1;
    kt();
    while (check == 1)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        sinh();
    }
}