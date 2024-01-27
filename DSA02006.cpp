#include <bits/stdc++.h>
using namespace std;
int n, k, a[105], b[105], flag;
void btrack(int x, int y, int z)
{
    for (int i = x + 1; i <= n; i++)
    {
        if (z + a[i] == k)
        {
            flag = 1;
            b[y + 1] = a[i];
            cout << "[" << b[0];
            for (int j = 1; j <= y + 1; j++)
                cout << " " << b[j];
            cout << "] ";
            return;
        }
        else if (z + a[i] < k)
        {
            b[y + 1] = a[i];
            btrack(i, y + 1, z + a[i]);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        flag = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        btrack(0, -1, 0);
        if (flag == 0)
            cout << -1 << endl;
        cout << endl;
    }
}