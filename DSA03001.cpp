#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0, cnt = 0;
        while (sum != n)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (a[i] <= n - sum)
                {
                    sum += a[i];
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << endl;
    }
}