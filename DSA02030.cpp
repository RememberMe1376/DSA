#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int n, k;
    cin >> c >> k;
    n = c - 'A' + 1;
    int a[k + 1];
    for (int i = 1; i <= k; i++)
        a[i] = 1;
    while (1)
    {
        for (int i = 1; i <= k; i++)
            cout << (char)(a[i] + 'A' - 1);
        cout << endl;
        int check = 0;
        for (int i = k; i >= 1; i--)
        {
            if (a[i] != n)
            {
                check = 1;
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[i];
                break;
            }
        }
        if (check == 0)
            break;
    }
}