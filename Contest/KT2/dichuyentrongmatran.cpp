#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int a[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i == 0 && j != 0)
            {
                a[i][j] += a[i][j - 1];
            }
            else if (i != 0 && j == 0)
            {
                a[i][j] += a[i - 1][j];
            }
            else if (i != 0 && j != 0)
            {
                a[i][j] += max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }
    cout << a[x - 1][y - 1] << endl;
}
