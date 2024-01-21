#include <bits/stdc++.h>
using namespace std;
void chuanhoa(string &s, int n)
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
    int k = v.size();
    if (n == 1)
    {
        cout << v[k - 1] << " ";
        for (int i = 0; i < k - 1; i++)
        {
            cout << v[i];
            if (i != k - 2)
                cout << " ";
        }
    }
    else
    {
        for (int i = 1; i < k; ++i)
            cout << v[i] << " ";
        cout << v[0];
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, s);
        chuanhoa(s, n);
        cout << endl;
    }
}