#include <bits/stdc++.h>
using namespace std;

void dfs(int src, int nodes, int time, vector<vector<double>> arr, double p, vector<double> ans)
{
    if (time <= 0)
    {
        ans[src] += p;
    }
    for (int i = 1; i <= nodes; i++)
    {
        if (arr[src][i] != 0)
        {
            p *= arr[src][i];
            dfs(i, nodes, time - 10, arr, p, ans);
            p /= arr[src][i];
        }
    }
}

int main()
{
    int t;
    while (t--)
    {
        int nodes, edges, time;
        cin >> nodes >> edges >> time;
        vector<vector<double>> arr(n + 1, vector<double>(n + 1, 0));
        for (int i = 0; i < edges; i++)
        {
            int x, y;
            double p;
            cin >> x >> y >> p;
            arr[x][y] = p;
        }
        vector<double> ans(n + 1, 0);
        dfs(1, nodes, time, arr, 1, ans);
        double maxProb = 0;
        int index = -1;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] > maxProb)
            {
                maxProb = ans[i];
                index = i;
            }
        }
        cout << index << maxProb << endl;
    }
}