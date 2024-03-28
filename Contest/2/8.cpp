#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> v, res;
int b[100];
void in()
{
    for (int i = 1; i <= k; ++i)
    {
        cout << v[b[i] - 1] << " ";
        cout << endl;
    }
}
void Try(int i)
{
    for (int j = b[i - 1] + 1; j <= v.size() - k + i; ++j)
    {
        b[i] = j;
        if (i == k)
            in();
        else
            Try(i + 1);
    }
}
int main()
{
    cin >> n >> k;
    string s;
    map<string, bool> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        mp[s] = 1;
    }
    for (auto &it : mp)
        v.push_back(it.first);
    Try(1);
}