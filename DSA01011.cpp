#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int x = s.size();
        int i = x - 2;
        while (s[i + 1] <= s[i])
            i--;
        if (i < 0)
            cout << n << " BIGGEST" << endl;
        else
        {
            int k = x - 1;
            while (s[i] >= s[k])
                k--;
            swap(s[i], s[k]);
            sort(s.begin() + i + 1, s.end());
            cout << n << " " << s << endl;
        }
    }
}