#include <bits/stdc++.h>
using namespace std;

int n, len;
unordered_map<string, unordered_set<string>> mp;
unordered_map<string, int> degree;
bool check = true;

bool kahn()
{
    int cnt = 0;

    queue<string> q;
    for (auto x : mp)
    {
        if (!degree[x.first])
        {
            q.push(x.first);
        }
    }

    while (!q.empty())
    {
        auto x = q.front();
        q.pop();

        cnt++;

        for (auto u : mp[x])
        {
            degree[u]--;
            if (!degree[u])
                q.push(u);
        }
    }

    if (cnt == len)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    cin >> n;

    unordered_map<string, int> dem;

    for (int i = 0; i < n; i++)
    {
        string a, b;
        char c;
        cin >> a >> c >> b;
        if (c == '>')
        {
            mp[a].insert(b);
            degree[b]++;
        }
        else
        {
            mp[b].insert(a);
            degree[a]++;
        }
        dem[a]++;
        dem[b]++;
        if (dem[a] == 1)
            len++;
        if (dem[b] == 1)
            len++;
    }

    check = kahn();

    if (check)
        cout << "possible\n";
    else
        cout << "impossible\n";

    return 0;
}