#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int b1[n1], b2[n2];
    for (int i = 0; i < n1; i++)
        b1[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        b2[i] = a[m + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (b1[i] <= b2[j])
        {
            a[k] = b1[i];
            i++;
        }
        else
        {
            a[k] = b2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = b1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = b2[j];
        j++;
        k++;
    }
}
void MergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        MergeSort(a, 0, n - 1);
        for (auto it : a)
            cout << it << " ";
        cout << endl;
    }
}