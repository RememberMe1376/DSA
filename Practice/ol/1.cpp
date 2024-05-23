#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> v;
int check1(vector<int> a)
{
    int s = 0;
    for (int i = 1; i < a.size(); i++)
    {
        s += a[i] - a[i - 1];
    }
    if (s > 0)
        return 0;
    return 1;
}
vector<int> b;
void sinh(int n)
{
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (1)
    {
        for (int i = 1; i <= n; i++)
            b.push_back(a[i]);
        if (check1(b))
            v.push_back(b);
        b.clear();
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
}
int main()
{
    cin >> n;
    sinh(n);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}