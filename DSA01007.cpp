#include <bits/stdc++.h>
using namespace std;
void sinh(int n)
{
    string a;
    for (int i = 0; i < n; i++)
        a += 'A';
    while (1)
    {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << " ";
        int check = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] == 'A')
            {
                check = 1;
                a[i] = 'B';
                for (int j = i + 1; j < n; j++)
                    a[j] = 'A';
                break;
            }
        }
        if (check == 0)
            break;
    }
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
        cout << endl;
    }
}