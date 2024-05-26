#include <bits/stdc++.h>
using namespace std;

int n, v, f, c[1005], w[1005], x[1005], res[1005];

void score(int a)
{
    f = a;
    for (int i = 1; i <= n; i++)
        res[i] = x[i];
}

void Try(int i, int a, int b)
{
    for (int j = 0; j <= 1; j++)
    {
        if (b + j * w[i] > v)
            continue;
        x[i] = j;
        if (i == n && a + j * c[i] > f)
            score(a + j * c[i]);
        if (i < n)
            Try(i + 1, a + j * c[i], b + j * w[i]);
    }
}
int main()
{
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    f = -1e9;
    Try(1, 0, 0);
    cout << f << endl;
    for (int i = 0; i <= n; i++)
        cout << res[i] << " ";
}