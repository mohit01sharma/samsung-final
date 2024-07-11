#include <bits/stdc++.h>
using namespace std;

void updateMatrix(int row, int **arr)
{
    int limit = max(row - 4, 0);
    for (int i = row; i >= limit; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 2)
                arr[i][j] = 0;
        }
    }
}

int solve(int row, int col, int **arr, int bomb, vector<vector<vector<int>>> &dp)
{
    if (row < 0)
        return 0;
    if (dp[row][col][bomb] != -1)
        return dp[row][col][bomb];
    int opt1 = 0;
    if (row - 1 >= 0 && col + 1 < 5 && arr[row - 1][col + 1] == 0)
        opt1 = solve(row - 1, col + 1, arr, bomb, dp);
    if (row - 1 >= 0 && col + 1 < 5 && arr[row - 1][col + 1] == 1)
        opt1 = 1 + solve(row - 1, col + 1, arr, bomb, dp);
    int opt2 = 0;
    if (row - 1 >= 0 && col - 1 >= 0 && arr[row - 1][col - 1] == 0)
        opt2 = solve(row - 1, col - 1, arr, bomb, dp);
    if (row - 1 >= 0 && col - 1 >= 0 && arr[row - 1][col - 1] == 1)
        opt2 = 1 + solve(row - 1, col - 1, arr, bomb, dp);
    int opt3 = 0;
    if (row - 1 >= 0 && arr[row - 1][col] == 0)
        opt3 = solve(row - 1, col, arr, bomb, dp);
    if (row - 1 >= 0 && arr[row - 1][col] == 1)
        opt3 = 1 + solve(row - 1, col, arr, bomb, dp);
    int ans = max({opt1, opt2, opt3});
    if (ans == 0 && bomb > 0)
    {
        updateMatrix(row - 1, arr);
        ans = solve(row, col, arr, bomb - 1, dp);
    }
    return dp[row][col][bomb] = ans;
}

int main()
{
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int row;
        cin >> row;
        int **arr = new int *[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[5];
            for (int j = 0; j < 5; j++)
            {
                cin >> arr[i][j];
            }
        }
        vector<vector<vector<int>>> dp(row + 3, vector<vector<int>>(5, vector<int>(2, -1)));
        cout << "#" << p << " " << solve(row, 2, arr, 1, dp) << endl;
    }
}