#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph(15, vector<int>(15, 0));

int findCost(int mask, int src, vector<vector<int>> &dp)
{

    if (mask == ((1 << (n)) - 1))
    {
        if (graph[src][0] != 0)
            return graph[src][0];
        return 1e9;
    }

    if (dp[mask][src] != -1)
        return dp[mask][src];
    int cost = 1e9;

    for (int node = 0; node < n; node++)
    {
        if ((mask & (1 << node)) == 0 && graph[src][node] != 0)
        {
            cost = min(cost, findCost((mask | (1 << node)), node, dp) + graph[src][node]);
        }
    }

    return dp[mask][src] = cost;
}

int solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int wt;
            cin >> wt;
            graph[i][j] = wt;
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    int ans = findCost(1, 0, dp);

    return ans;
}

int main()
{

    for (int test = 1; test <= 10; test++)
    {
        cout << "# " << test << " ";
        int ans = solve();
        cout << ans << "\n";
    }
    return 0;
}