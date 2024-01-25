#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<vector<int>> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = k;
        v.push(a);
    }
    int d = n - 1;
    while (!v.empty())
    {
        a = v.top();
        v.pop();
        cout << "Buoc " << d-- << ": ";
        for (int j = 0; j <= d + 1; j++)
            cout << a[j] << " ";
        cout << endl;
    }
}