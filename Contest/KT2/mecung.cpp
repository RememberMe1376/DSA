#include <bits/stdc++.h>
using namespace std;

int p[100005], psize[100005];

int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

bool Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return false;
    if (psize[x] < psize[y])
        swap(x, y);
    p[y] = x;
    psize[x] += psize[y];
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int dinh, canh;
        cin >> dinh >> canh;
        for (int i = 1; i <= dinh; i++)
        {
            p[i] = i;
            psize[i] = 1;
        }
        vector<pair<int, int>> v;
        while (canh--)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        int check = 0;
        for (auto i : v)
        {
            if (!Union(i.first, i.second))
            {
                check = 1;
                break;
            }
        }
        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
