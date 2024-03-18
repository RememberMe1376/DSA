#include <bits/stdc++.h>
using namespace std;
int count(const string &s)
{
    int cnt = 0;
    for (char c : s)
    {
        if (c == 'A')
            cnt++;
    }
    return cnt;
}
int fibo(int n)
{
    string f0 = "A";
    string f1 = "B";
    int cnt = 0;
    if (n == 0)
        return count(f0);
    else if (n == 1)
        return count(f1);
    for (int i = 2; i <= n; i++)
    {
        string fn = f0 + f1;
        cnt++;
        cnt += count(fn);
        f0 = f1;
        f1 = fn;
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}