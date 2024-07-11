#include <bits/stdc++.h>
using namespace std;

int xb, yb, xt, yt;

int solve(vector<vector<int>> dp, int n, int m, int mid)
{
    int m_sum = INT_MAX;
    for (int i = 0; i <= n - mid; i++)
    {
        for (int j = 0; j <= m - mid; j++)
        {
            int sum = dp[i + k][j + k] - dp[i + k][j] - dp[i][j + k] + dp[i][j];
            if (sum < m_sum)
            {
                m_sum = sum;
                if (sum <= 1)
                {
                    xb = i + k;
                    yb = j + 1;
                    xt = i + 1;
                    xt = j + k;
                }
            }
        }
    }
    return m_sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = 0;
        }
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = 1;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = arr[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }
    int l = 1;
    int r = min(n, m);
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (func(dp, n, m, mid) <= 1)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << xb << yb << xt << yt;
}