#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n] = {};
    vector<int> v1, v2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
        {
            b[i] = 1;
            v1.push_back(a[i]);
        }
        else
            v2.push_back(a[i]);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    sort(v2.begin(), v2.end());
    int l1 = 0, l2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
        {
            a[i] = v2[l1];
            l1++;
        }
        else
        {
            a[i] = v1[l2];
            l2++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}