#include <bits/stdc++.h>
using namespace std;
void gen(vector<int> &num, vector<string> &s, int pos, string cur)
{
    if (pos == num.size())
    {
        s.push_back(cur);
        return;
    }
    for (int i = pos; i < num.size(); i++)
    {
        cur += to_string(num[i]);
        gen(num, s, i + 1, cur);
        cur.erase(cur.size() - to_string(num[i]).size());
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    vector<string> s;
    gen(num, s, 0, "");
    sort(s.begin(), s.end());
    for (const string &x : s)
        cout << x << endl;
}