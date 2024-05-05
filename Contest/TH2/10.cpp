#include <bits/stdc++.h>
using namespace std;
int V, E, S, T, u, v;
vector<vector<int>> G;
vector<int> Tr;
vector<bool> Vs;
void bfs()
{
    queue<int> q;
    q.push(S);
    Vs[S] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        if (u == T)
            return;
        for (int i = 0; i < G[u].size(); ++i)
        {
            v = G[u][i];
            if (!Vs[v])
            {
                q.push(v);
                Tr[v] = u;
                Vs[v] = 1;
            }
        }
    }
}
void track()
{
    if (!Vs[T])
    {
        cout << -1;
        return;
    }
    stack<int> st;
    st.push(T);
    int last = Tr[T];
    while (last != -1)
    {
        st.push(last);
        last = Tr[st.top()];
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> V >> E >> S >> T;
        G.clear();
        G.resize(V + 1);
        Vs.clear();
        Vs.resize(V + 1, 0);
        Tr.clear();
        Tr.resize(V + 1, -1);
        for (int i = 1; i <= E; ++i)
        {
            cin >> u >> v;
            G[u].push_back(v);
        }
        for (int i = 1; i <= V; ++i)
            sort(G[i].begin(), G[i].end());
        bfs();
        track();
        cout << endl;
    }
}