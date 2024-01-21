#include <bits/stdc++.h>
using namespace std;
int prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        set<int> se;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (prime(x))
                se.insert(x);
        }
        for (auto it : se)
            cout << it << " ";
        cout << endl;
    }
}