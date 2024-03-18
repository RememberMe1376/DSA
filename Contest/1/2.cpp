#include <bits/stdc++.h>
using namespace std;
void gen(vector<int> &v, int n, int k, int start)
{
    if (k == 0)
    {
        for (int it : v)
            cout << it << " ";
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        v.push_back(i);
        gen(v, n, k - 1, i);
        v.pop_back();
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    gen(v, n, k, 1);
}