#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        string s = to_string(n);
        sort(s.begin(), s.end());
        char min = s[0];
        char max = s[s.length() - 1];
        cout << max << " " << min << endl;
    }
}
