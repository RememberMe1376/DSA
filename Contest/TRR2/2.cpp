#include <bits/stdc++.h>
using namespace std;

void readG(ifstream &infile, int &t, int &n, int &u, vector<vector<int>> &G)
{
    infile >> t;
    if (t == 1)
    {
        infile >> n;
        G.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                infile >> G[i][j];
            }
        }
    }
    else if (t == 2)
    {
        infile >> n >> u;
        --u;
        G.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                infile >> G[i][j];
            }
        }
    }
}

int checkEuler(vector<vector<int>> &G)
{
    int n = G.size();
    int oddDegCount = 0;
    for (int i = 0; i < n; ++i)
    {
        int degree = 0;
        for (int j = 0; j < n; ++j)
        {
            degree += G[i][j];
        }
        if (degree % 2 != 0)
        {
            ++oddDegCount;
        }
    }
    if (oddDegCount == 0)
        return 1;
    if (oddDegCount == 2)
        return 2;
    return 0;
}

void findEulerCycle(vector<vector<int>> &G, int u, ofstream &outfile)
{
    stack<int> st;
    vector<int> path;
    st.push(u);
    while (!st.empty())
    {
        int v = st.top();
        int i;
        for (i = 0; i < G.size(); ++i)
        {
            if (G[v][i] == 1)
            {
                st.push(i);
                G[v][i] = 0;
                G[i][v] = 0;
                break;
            }
        }
        if (i == G.size())
        {
            path.push_back(v);
            st.pop();
        }
    }
    for (int i = path.size() - 1; i >= 0; --i)
    {
        outfile << path[i] + 1 << " ";
    }
}

int main()
{
    ifstream infile("CT.INP");
    ofstream outfile("CT.OUT");
    int t, n, u;
    vector<vector<int>> G;

    readG(infile, t, n, u, G);
    if (t == 1)
    {
        int result = checkEuler(G);
        outfile << result;
    }
    else if (t == 2)
    {
        findEulerCycle(G, u - 1, outfile);
    }

    infile.close();
    outfile.close();
    return 0;
}
