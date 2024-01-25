#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int> a, int n)
{
    vector<vector<int>> v;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
        v.push_back(a);
    }
    int m = v.size();
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << "Buoc " << m << ": ";
        m--;
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    selectionSort(v, n);
}