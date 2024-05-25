#include <bits/stdc++.h>
using namespace std;

int n, m;
char c[1005][1005];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j)
{
    c[i][j] = '.';
    for (int k = 0; k < 8; k++)
    {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && c[i1][j1] == 'W')
            dfs(i1, j1);
    }
}

int main()
{
    int cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == 'W')
            {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}
