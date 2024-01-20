#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[10] = {}, x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            while (x != 0)
            {
                int k = x % 10;
                a[k]++;
                x /= 10;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (a[i] > 0)
                cout << i << " ";
        }
        cout << endl;
    }
}