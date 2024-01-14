#include <bits/stdc++.h>
using namespace std;
void sinh(int n)
{
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << " ";
        int check = 0;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1])
            {
                check = 1;
                sort(a + i + 1, a + n + 1);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j] > a[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (check == 0)
            break;
    }
    cout << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        sinh(n);
    }
}