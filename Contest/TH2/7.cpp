#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, m;
int A[1005][1005];
int dp[1005][1005];
void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    dp[i][j] = 0;
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        int a = x.first, b = x.second;
        if (a == n && b == m)
            break;
        int a1, b1;
        if (a + 1 <= n)
        {
            a1 = a + abs(A[a][b] - A[a + 1][b]), b1 = b;
            if (dp[a1][b1] == 1e9 && a1 <= n)
            {
                dp[a1][b1] = dp[a][b] + 1;
                q.push({a1, b1});
            }
        }
        if (b + 1 <= m)
        {
            a1 = a;
            b1 = b + abs(A[a][b] - A[a][b + 1]);
            if (dp[a1][b1] == 1e9 && b1 <= m)
            {
                dp[a1][b1] = dp[a][b] + 1;
                q.push({a1, b1});
            }
        }
        if (a + 1 <= n && b + 1 <= m)
        {
            a1 = a + abs(A[a][b] - A[a + 1][b + 1]);
            b1 = b + abs(A[a][b] - A[a + 1][b + 1]);
            if (dp[a1][b1] == 1e9 && (a1 <= n) && (b1 <= m))
            {
                dp[a1][b1] = dp[a][b] + 1;
                q.push({a1, b1});
            }
        }
    }
    return;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> A[i][j];
                dp[i][j] = 1e9;
            }
        }
        bfs(1, 1);
        if (dp[n][m] == 1e9)
            cout << -1;
        else
            cout << dp[n][m];
        cout << endl;
    }
}