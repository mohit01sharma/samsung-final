#include <bits/stdc++.h>
using namespace std;

int n;
int solve(int mask, int a[], int LtoR, vector<vector<int>> &dp)
{
    if (mask == (1 << n) - 1)
    {
        return 0;
    }
    if (dp[LtoR][mask] != -1)
        return dp[LtoR][mask];
    if (LtoR)
    {
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!(mask & (1 << i)) && !(mask & (1 << j)))
                {
                    int x = (mask | (1 << i)) | (1 << j);
                    ans = min(ans, max(a[i], a[j]) + solve(x, a, 1 - LtoR, dp));
                }
            }
        }
        return dp[LtoR][mask] = ans;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            int x = mask & (~(1 << i));
            ans = min(ans, a[i] + solve(x, a, 1 - LtoR, dp));
        }
    }
    return dp[LtoR][mask] = ans;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<int>> dp(2, vector<int>((1 << n) + 1, -1));
        cout << solve(0, a, 1, dp) << endl;
    }
}
