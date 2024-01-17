#include <bits/stdc++.h>
using namespace std;
int n, x[100], c[100], d1[100], d2[100], cnt = 0;
void btrack(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (c[j] == 1 && d1[i - j + n] == 1 && d2[i + j - 1] == 1)
        {
            c[j] = d1[i - j + n] = d2[i + j - 1] = 0;
            x[i] = j;
            if (i == n)
                ++cnt;
            else
                btrack(i + 1);
            c[j] = d1[i - j + n] = d2[i + j - 1] = 1;
        }
    }
}
int main()
{
    for (int i = 1; i <= 100; i++)
        c[i] = d1[i] = d2[i] = 1;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cnt = 0;
        btrack(1);
        cout << cnt << endl;
    }
}