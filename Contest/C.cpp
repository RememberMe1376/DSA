#include <bits/stdc++.h>
using namespace std;
int main()
{
    int max = 0;
    string a, b = "";
    while (cin >> a)
    {
        if (a.size() > max)
        {
            max = a.size();
            b = a;
        }
    }
    cout << b << " - " << max;
}