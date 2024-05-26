#include <bits/stdc++.h>
using namespace std;

vector<string> genGray(int n)
{
    if (n == 1)
    {
        return {"0", "1"};
    }
    vector<string> prev = genGray(n - 1);
    vector<string> result;
    for (const string &s : prev)
    {
        result.push_back("0" + s);
    }
    for (int i = prev.size() - 1; i >= 0; i--)
    {
        result.push_back("1" + prev[i]);
    }

    return result;
}

void gen(int n)
{
    vector<string> gray = genGray(n);
    for (const string &s : gray)
    {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        gen(n);
    }
    return 0;
}
