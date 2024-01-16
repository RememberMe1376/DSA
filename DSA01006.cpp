#include <bits/stdc++.h>
using namespace std;
void sinh(int n)
{
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    vector<string> v;
    while (1)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(a[i]);
        v.push_back(s);
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
    while (v.size())
    {
        cout << v[v.size() - 1] << " ";
        v.pop_back();
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