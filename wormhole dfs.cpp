#include <bits/stdc++.h>
using namespace std;

int ans = INT_MAX;

void dfs(int sx, int sy, int tx, int ty, int val, vector<vector<int>> w, vector<int> &vis)
{
    ans == min(ans, val + abs(sx - tx) + abs(sy - ty));
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            dfs(w[i][0], w[i][1], tx, ty, val + abs(sx - w[i][2]) + abs(sy - w[i][3]) + w[i][4], w, vis);
            dfs(w[i][2], w[i][3], tx, ty, val + abs(sx - w[i][0]) + abs(sy - w[i][1]) + w[i][4], w, vis);
            vis[i] = 0;
        }
    }
}

int main()
{
    int n, sx, sy, tx, ty;
    cin >> n, sx, sy, tx, ty;
    vector<vector<int>> arr(n, vector<int>(5));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> vis(n, 0);
    dfs(sx, sy, tx, ty, 0, arr, vis);
    cout << ans;
}