#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v)
        cout << it.first << " " << it.second << " " << endl;
}