#include <bits/stdc++.h>
using namespace std;
struct cv
{
    int deadline, profit;
};
bool cmp(cv a, cv b)
{
    if (a.deadline == b.deadline)
        return a.profit > b.profit;
    return a.deadline > b.deadline;
}
int main()
{
    int n;
    cin >> n;
    cv a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].deadline >> a[i].profit;
    sort(a, a + n, cmp);
    priority_queue<long long> q;
    long long sum = 0, x = 0;
    for (int i = n; i >= 1; i--)
    {
        while (x < n && a[x].deadline >= i)
        {
            q.push(a[x].profit);
            x++;
        }
        if (!q.empty())
        {
            sum += q.top();
            q.pop();
        }
    }
    cout << sum;
}