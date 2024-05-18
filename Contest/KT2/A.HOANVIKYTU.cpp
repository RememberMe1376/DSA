#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c1, c2;
    cin >> c1 >> c2;
    string a;
    for (char x = min(c1, c2); x <= max(c1, c2); x++)
        a += x;
    do
    {
        cout << a << endl;
    } while (next_permutation(a.begin(), a.end()));
}