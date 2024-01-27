#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> a, int n)
{
    stack<vector<int>> st;
    for (int i = 0; i < n - 1; i++)
    {
        int k = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                k = 1;
            }
        }
        if (k == 0)
            break;
        st.push(a);
    }
    int m = st.size();
    while (!st.empty())
    {
        a = st.top();
        st.pop();
        cout << "Buoc " << m-- << ": ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        bubbleSort(v, n);
    }
}