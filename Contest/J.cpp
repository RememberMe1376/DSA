#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    set<int> se;
    int n = s.size();
    if (n % 2 == 0)
        n = s.size();
    else
        n = s.size() - 1;
    for (int i = 0; i < n; i += 2)
    {
        int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
        se.insert(x);
    }
    for (auto it : se)
        cout << it << " ";
}