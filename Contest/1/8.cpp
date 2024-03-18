#include <bits/stdc++.h>
using namespace std;
int x[1005] = {};
int ans[1005] = {};
void nt(int a, int b)
{
    for (int i = 2; i <= sqrt(a); i++)
    {
        while (a % i == 0)
        {
            x[i] += b;
            a /= i;
        }
    }
    if (a > 1)
        x[a] += b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(x, 0, sizeof(x));
        memset(ans, 0, sizeof(ans));
        for (int i = n + 1; i <= n * 2; i++)
            nt(i, 1);
        for (int i = 2; i <= n + 1; i++)
            nt(i, -1);
        int l = 1;
        ans[0] = 1;
        for (int i = 2; i <= n * 2; i++)
        {
            while (x[i]--)
            {
                l += 5;
                for (int j = 0; j < l; j++)
                    ans[j] *= i;
                for (int j = 1; j < l; j++)
                {
                    ans[j] = ans[j - 1] / 10 + ans[j];
                    ans[j - 1] %= 10;
                }
                while (ans[l - 1] == 0)
                    l--;
            }
        }
        for (int i = l - 1; i >= 0; i--)
            cout << ans[i];
        cout << endl;
    }
}