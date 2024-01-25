#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a, b;
vector<vector<int>> res;
void push()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
            sum += b[i];
    }
    if (sum == k)
        res.push_back(a);
}
void btrack(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n - 1)
            push();
        else
            btrack(i + 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        a.resize(n, 0);
        b.resize(n, 0);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        btrack(0);
        for (int i = 0; i < res.size(); i++)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (res[i][j] == 1)
                {
                    cout << b[j];
                }
            }
            cout << "]";
        }
        cout << " ";
    }
}