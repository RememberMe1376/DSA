#include <bits/stdc++.h>
using namespace std;
void InterchangeSort(vector<int> a, int n)
{
    vector<vector<int>> b;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
        b.push_back(a);
    }
    int m = b.size();
    for (int i = b.size() - 1; i >= 0; i--)
    {
        cout << "Buoc " << m << ": ";
        m--;
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        InterchangeSort(v, n);
    }
}