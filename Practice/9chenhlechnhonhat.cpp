#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int x[k + 1], res = 1e9;
    vector<string> v1(n);
    vector<string> v2;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
        v1[i] = "0" + v1[i];
    }
    for (int i = 1; i <= k; i++)
        x[i] = i;
    while (1)
    {
        v2.clear();
        for (int i = 0; i < n; i++)
        {
            string s = v1[i];
            for (int j = 1; j <= k; j++)
                s[j] = v1[i][x[j]];
            v2.push_back(s);
        }
        sort(v2.begin(), v2.end());
        res = min(res, stoi(v2[v2.size() - 1]) - stoi(v2[0]));
        int flag = 0;
        for (int i = k - 1; i >= 1; i--)
        {
            if (x[i] < x[i + 1])
            {
                flag = 1;
                sort(x + i + 1, x + k + 1);
                for (int j = i + 1; j <= k; j++)
                {
                    if (x[j] > x[i])
                    {
                        swap(x[i], x[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (flag == 0)
            break;
    }
    cout << res;
}