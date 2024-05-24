#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, res = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
        {
            int x = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[x])
                    x = j;
            }
            if (x != i)
                res++;
            swap(a[i], a[x]);
        }
        cout << res << endl;
    }
}