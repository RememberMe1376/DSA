#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<long long> v1, v2;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            v1.push_back(a[i]);
        else
            v2.push_back(a[i]);
    }
    sort(v2.begin(), v2.end(), greater<long long>());
    sort(v1.begin(), v1.end());
    int j = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            cout << v1[j] << " ";
            j++;
        }
        else
        {
            cout << v2[k] << " ";
            k++;
        }
    }
}