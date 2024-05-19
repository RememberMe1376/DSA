#include <bits/stdc++.h>

using namespace std;

const int INF = 10000;

vector<int> bellmanFord(vector<vector<int>> &graph, int n, int s, int t)
{
    vector<int> distance(n, INF);
    vector<int> prev(n, -1);

    distance[s] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (graph[u][v] != INF && distance[u] + graph[u][v] < distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    vector<int> path;
    int cur = t;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = prev[cur];
    }
    reverse(path.begin(), path.end());

    return path;
}

bool hasNegativeCycle(vector<vector<int>> &graph, int n)
{
    vector<int> distance(n, INF);
    distance[0] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (graph[u][v] != INF && distance[u] + graph[u][v] < distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }
    }

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != INF && distance[u] + graph[u][v] < distance[v])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ifstream inputFile("DN.INP");
    ofstream outputFile("DN.OUT");

    int n, s, t;
    inputFile >> n >> s >> t;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            inputFile >> graph[i][j];
            if (i != j && graph[i][j] == 0)
            {
                graph[i][j] = INF;
            }
        }
    }

    if (hasNegativeCycle(graph, n))
    {
        outputFile << "-1" << endl;
    }
    else
    {
        vector<int> shortestPath = bellmanFord(graph, n, s - 1, t - 1);

        if (shortestPath.empty())
        {
            outputFile << "0" << endl;
        }
        else
        {
            outputFile << shortestPath.size() - 1 << endl;
            for (int i = 0; i < shortestPath.size(); ++i)
            {
                outputFile << shortestPath[i] + 1 << " ";
            }
            outputFile << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
