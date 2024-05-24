#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin.ignore();
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        s += ' ';
        int k = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (isdigit(s[j]))
                k = k * 10 + s[j] - '0';
            else
            {
                a[i][k] = a[k][i] = 1;
                k = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}