#include <bits/stdc++.h>
using namespace std;
void chuanhoa(string &s)
{
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    string x = "";
    stringstream ss(s);
    vector<string> v;

    while (ss >> x)
    {
        x[0] = toupper(x[0]);
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}
int main()
{
    string s;
    getline(cin, s);
    chuanhoa(s);
}