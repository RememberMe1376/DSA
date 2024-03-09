#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x = 0;
        cin >> n;
        string a;
        for (int i = 0; i < n; i++)
            a += 'A';
        cout << a;
        while (1)
        {
            if (x != 0)
                cout << "," << a;
            x++;
            int flag = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 'A')
                {
                    flag = 1;
                    a[i] = 'B';
                    for (int j = i + 1; j < n; j++)
                        a[j] = 'A';
                    break;
                }
            }
            if (flag == 0)
                break;
        }
    }
    cout << endl;
}