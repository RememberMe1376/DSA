// 1
bool vs[1005] = {false};
int a[1005][1005], n;
void DFS(int u)
{
    vs[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] && !vs[v])
            DFS(v);
    }
}
// 2
bool vs[1005] = {false};
int a[1005][1005], n;
void BFS(int u)
{
    queue<int> q;
    vs[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        cout << s << " ";
        for (int v = 0; v < n; v++)
        {
            if (a[s][v] && !vs[v])
            {
                vs[v] = true;
                q.push(v);
            }
        }
    }
}
// 3
bool vs[1005] = {false};
int a[1005][1005], n;
void DFS(int u)
{
    vs[u] = true;
    for (int v = 0; v < n; v++)
    {
        if (a[u][v] && !vs[v])
            DFS(v);
    }
}

int TPLT_DFS(int a[][])
{
    int cnt = 0;
    memset(vs, false, sizeof vs);
    for (int u = 0; u < n; u++)
    {
        if (!vs[u])
        {
            DFS(u);
            cnt++;
        }
    }
    return cnt;
}

// 4
bool vs[1005] = {false};
int a[1005][1005], n;
void BFS(int u)
{
    queue<int> q;
    vs[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (a[s][v] && !vs[v])
            {
                vs[v] = true;
                q.push(v);
            }
        }
    }
}

int TPLT_BFS(int a[][])
{
    int cnt = 0;
    memset(vs, false, sizeof vs);
    for (int u = 0; u < n; u++)
    {
        if (!vs[u])
        {
            BFS(u);
            cnt++;
        }
    }
    return cnt;
}
// 5
int a[100][100], n, u, vs[100], e[100];

void DFS(int u)
{
    int v;
    vs[u] = 1;
    for (v = 1; v <= n; v++)
        if (vs[v] == 0 && a[u][v] == 1)
        {
            e[v] = u;
            DFS(v);
        }
}

void T_DFS(int a[][100])
{
    int v;
    for (v = 1; v <= n; v++)
        vs[v] = 0;
    DFS(1);
    int dem = 0;
    for (v = 1; v <= n; v++)
        if (vs[v] == 1)
            dem++;
    if (dem == n)
    {
        for (v = 1; v <= n; v++)
            if (e[v] != 0)
                cout << v << " " << e[v] << endl;
    }
    else
        cout << "Not found";
}
// 6
int a[100][100], n, u, vs[100], e[100], q[100];

void BFS(int u)
{
    int v, dq = 1, cq = 0;
    cq++;
    q[cq] = u;
    vs[u] = 1;

    while (dq <= cq)
    {
        v = q[dq];
        dq++;

        for (int i = 1; i <= n; i++)
            if (vs[i] == 0 && a[v][i] == 1)
            {
                cq++;
                q[cq] = i;
                vs[i] = 1;
                e[i] = v;
            }
    }
}

void T_BFS(int a[][100])
{
    int v;
    for (v = 1; v <= n; v++)
        vs[v] = 0;

    BFS(1);
    int dem = 0;
    for (v = 1; v <= n; v++)
        if (vs[v] == 1)
            dem++;

    if (dem == n)
    {
        for (v = 1; v <= n; v++)
            if (e[v] != 0)
                cout << v << " " << e[v] << endl;
    }
    else
        cout << "Not found";
}
// 7
void EULER(int a[][], int n, int u)
{
    int CE[1005];
    stack<int> st;
    st.push(u);
    int t = 1;
    while (!st.empty())
    {
        int v = st.top();
        int x = 1;
        while (x <= n && a[v][x] == 0)
            x++;
        if (x <= n)
        {
            st.push(x);
            a[v][x] = 0 a[x][v] = 0;
        }
        else
        {
            CE[t] = v;
            t++;
            st.pop();
        }
    }
    for (int i = t - 1; i > 0; i--)
        cout << CE[i] << " ";
}
// 8
int n, u, a[100][100], d[100], e[100], vs[100];
void DIJKSTRA(int u)
{
    int s, v;
    for (v = 1; v <= n; v++)
    {
        d[v] = a[u][v];
        e[v] = u;
    }
    d[u] = 0;
    e[u] = 0;
    vs[u] = 1;
    while (1)
    {
        int s = 0, min = 1e9;
        for (v = 1; v <= n; v++)
            if (vs[v] == 0 && d[v] < min)
            {
                s = v;
                min = d[v];
            }
        if (s == 0)
            return;
        vs[s] = 1;
        for (v = 1; v <= n; v++)
            if (vs[v] == 0 && d[v] > d[s] + a[s][v])
            {
                d[v] = d[s] + a[s][v];
                e[v] = s;
            }
    }
}
// 9
int n, a[100][100], d[100][100], e[100][100];
int FLOYD(int a[][100])
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            d[i][j] = a[i][j];
            e[i][j] = i;
        }
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    e[i][j] = k;
                }
    for (i = 1; i <= n; i++)
        if (d[i][i] < 0)
            return 0;
    return 1;
}
// 10
int n, a[100][100], vs[100], d[100], e[100];
void PRIM(int a[][100], int u)
{
    for (int v = 1; v <= n; v++)
    {
        vs[v] = 0;
        d[v] = a[u][v];
        e[v] = u;
    }
    vs[u] = 1;
    d[u] = 0;
    e[u] = 0;
    int wt = 0, dem = 1, v;
    while (dem <= n)
    {
        int s = 0;
        int min = 30000;
        for (v = 1; v <= n; v++)
            if (vs[v] == 0 && d[v] < min)
            {
                min = d[v];
                s = v;
                dem++;
            }
        if (s == 0)
        {
            cout << "Not found";
            return;
        }
        vs[s] = 1;
        wt = wt + a[s][e[s]];
        for (v = 1; v <= n; v++)
            if (vs[v] == 0 && d[v] > a[s][v])
            {
                d[v] = a[s][v];
                e[v] = s;
            }
    }
    cout << wt << endl;
    for (v = 1; v <= n; v++)
        if (e[v] != 0)
            cout << v << " " << e[v] << endl;
    return;
}
// 11
int parent[1005];
int rank[1005];
struct Edge
{
    int src, dest, weight;
};
vector<Edge> edges;
bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}
int find(int i)
{
    if (parent[i] != i)
    {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}
void unionSet(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rank[rootX] < rank[rootY])
    {
        parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY])
    {
        parent[rootY] = rootX;
    }
    else
    {
        parent[rootX] = rootY;
        rank[rootY]++;
    }
}
void KRUSKAL(int a[][])
{
    int n = MAXN;
    edges.clear();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                Edge e;
                e.src = i;
                e.dest = j;
                e.weight = a[i][j];
                edges.push_back(e);
            }
        }
    }
    sort(edges.begin(), edges.end(), compareEdges);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    vector<Edge> result;
    for (Edge e : edges)
    {
        int x = find(e.src);
        int y = find(e.dest);
        if (x != y)
        {
            result.push_back(e);
            unionSet(x, y);
        }
    }
    int sum = 0;
    for (Edge e : result)
    {
        cout << e.src << " - " << e.dest << "   weight: " << e.weight
             << endl;
        sum += e.weight;
    }
    cout <<”tong chi phi : “ << sum << endl;
}
// 12
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, s = 1, t;
int c[100][100];
int f[100][100];
int trace[100];
bool bfs()
{
    queue<int> q;
    q.push(s);
    memset(trace, -1, sizeof(trace));
    trace[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (trace[v] == -1 && c[u][v] - f[u][v] > 0)
            {
                q.push(v);
                trace[v] = u;
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}
int max_flow()
{
    int ans = 0;
    while (bfs())
    {
        int delta = INF;
        for (int v = t; v != s; v = trace[v])
        {
            int u = trace[v];
            delta = min(delta, c[u][v] - f[u][v]);
        }
        for (int v = t; v != s; v = trace[v])
        {
            int u = trace[v];
            f[u][v] += delta;
            f[v][u] -= delta;
        }
        ans += delta;
    }
    return ans;
}
int main()
{
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    cin >> n;
    t = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    int ans = max_flow();
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
