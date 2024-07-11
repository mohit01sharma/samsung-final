#include <bits/stdc++.h>
using namespace std;

void solve(int i, int sum, int m, int minV, int maxV, int nodes, vector<int> oil, vector<int> &vis, int companies, int &ans)
{
    if (visited[i])
    {
        minV = min(minV, sum);
        maxV = max(maxV, sum);
        if (nodes = companies - 1)
        {
            ans = min(ans, maxV - minV);
        }
        return;
    }
    int j = (i + 1) % m;
    visited[i] = 1;
    solve(j, sum + oil[i], m, minV, maxV, nodes, oil, vis, n, ans);
    minV = min(minV, sum);
    maxV = max(maxV, sum);
    solve(j, oil[i], m, minV, maxV, nodes + 1, oil, vis, n, ans);
    visited[i] = 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n, m;
        vector<int> vis(m, 0);
        vector<int> oil(m);
        for (int i = 0; i < m; i++)
        {
            cin >> oil[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            solve(0, 0, m, INT_MAX, INT_MIN, 0, oil, vis, n, ans);
        }
        cout << ans;
    }
}