#include <bits/stdc++.h>
using namespace std;
void read(ifstream &in, vector<vector<int>> &a)
{
    int n;
    in >> n;
    a.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> a[i][j];
        }
    }
}

void calc(const vector<vector<int>> &a, vector<int> &inDeg, vector<int> &outDeg)
{
    int n = a.size();
    inDeg.resize(n);
    outDeg.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            outDeg[i] += a[i][j];
            inDeg[j] += a[i][j];
        }
    }
}

void writeDeg(const vector<int> &inDeg, const vector<int> &outDeg, ofstream &out)
{
    int n = inDeg.size();
    for (int i = 0; i < n; i++)
    {
        out << inDeg[i] << " " << outDeg[i] << endl;
    }
}

void gen(const vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n = a.size();
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
                m++;
        }
    }
    b.resize(n, vector<int>(m, 0));
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                b[i][index] = 1;
                b[j][index] = -1;
                index++;
            }
        }
    }
}

void writeB(const vector<vector<int>> &b, ofstream &out)
{
    int n = b.size();
    int m = b[0].size();
    out << n << " " << m << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            out << b[i][j] << " ";
        }
        out << endl;
    }
}

int main()
{
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t;
    in >> t;
    if (t == 1)
    {
        vector<vector<int>> a;
        read(in, a);
        vector<int> inDeg, outDeg;
        calc(a, inDeg, outDeg);
        writeDeg(inDeg, outDeg, out);
    }
    else if (t == 2)
    {
        vector<vector<int>> a;
        read(in, a);
        vector<vector<int>> b;
        gen(a, b);
        writeB(b, out);
    }
    in.close();
    out.close();
}