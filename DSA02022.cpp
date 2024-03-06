#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v1 = {"02", "20", "22"};
    vector<string> v2 = {"02"};
    vector<string> v3 = {"2000", "2002", "2020", "2022", "2200", "2202", "2220", "2222"};
    for (auto i1 : v1)
        for (auto i2 : v2)
            for (auto i3 : v3)
                cout << i1 + "/" + i2 + "/" + i3 << endl;
}