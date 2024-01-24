#include <bits/stdc++.h>
using namespace std;
void thap(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    thap(n - 1, a, c, b);
    thap(1, a, b, c);
    thap(n - 1, b, a, c);
}
int main()
{
    char a = 'A', b = 'B', c = 'C';
    int n;
    cin >> n;
    thap(n, a, b, c);
}
// Giải theo biểu diễn nhị phân
// #include <bits/stdc++.h>
// using namespace std;
// void thapbinary(int n)
// {
//     int step = pow(2, n) - 1;
//     for (int i = 1; i <= step; i++)
//     {
//         int a = (i & i - 1) % 3;
//         int b = ((i | i - 1) + 1) % 3;
//         cout << (char)('A' + a) << " -> " << (char)('A' + b) << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     thapbinary(n);
// }