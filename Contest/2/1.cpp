#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[k + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= k; i++)
        a[i] = i;
    sort(b + 1, b + n + 1);
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << b[a[i]] << " ";
        cout << endl;
        int flag = 1;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n - k + i)
            {
                flag = 0;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[j - 1] + 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    cout << endl;
}