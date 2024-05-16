#include <bits/stdc++.h>
using namespace std;
int n, k, a[100], flag;
void init()
{
    for (int i = 0; i < k; i++)
        a[i] = i + 1;
}
void gen()
{
    int i = k - 1;
    while (i >= 0 && a[i] == n - k + i + 1)
        i--;
    if (i == -1)
        flag = 0;
    else
    {
        a[i]++;
        for (int j = i + 1; j < k; j++)
            a[j] = a[j - 1] + 1;
    }
}
int main()
{
    int t;
    cin >> t;
    cin >> k;
    set<string> se;
    vector<string> v;
    while (t--)
    {
        string s;
        cin >> s;
        if (se.find(s) == se.end())
        {
            se.insert(s);
            v.push_back(s);
        }
    }
    int m = v.size();
    init();
    flag = 1;
    set<string> ans;
    while (flag)
    {
        string tmp = "";
        for (int i = 0; i < k; i++)
        {
            int pos = a[i] - 1;
            tmp += v[pos];
        }
        ans.insert(tmp);
        gen();
    }
    for (string it : ans)
        cout << it << endl;
}