#include <bits/stdc++.h>

int hashValue(int a, int b, int c)
{
    return a * 10000 + b * 100 + c;
}

vector<vector<int>> dp(12, vector<int>(1000005, -1));

int solve(int spot, int n, int f1, int f2, int f3, int g1, int g2, int g3)
{
    if (f1 < 0 || f2 < 0 || f3 < 0)
        return INT_MAX / 2;
    if (spot > n)
    {
        if (f1 == 0 && f2 == 0 && f3 == 0)
            return 0;
        else
            return INT_MAX / 2;
    }
    int hash = hashVaue(f1, f2, f3);
    if (dp[spot][hash] != -1)
        return dp[spot][hash];
    int opt1 = solve(spot + 1, n, f1, f2, f3, g1, g2, g3);
    int opt2 = 1 + abs(spot - g1) + solve(spot + 1, n, f1 - 1, f2, f3, g1, g2, g3);
    int opt3 = 1 + abs(spot - g2) + solve(spot + 1, n, f1, f2 - 1, f3, g1, g2, g3);
    int opt4 = 1 + abs(spot - g3) + solve(spot + 1, n, f1, f2, f3 - 1, g1, g2, g3);
    return dp[spot][hash] = min({opt1, opt2, opt3, opt4});
}

int main()
{
    int n;
    cin >> n;
    int gate1, gate2, gate3;
    cin >> gate1 >> gate2 >> gate3;
    int fisherman1, fisherman2, fisherman3;
    cin >> fisherman1 >> fisherman2 >> fisherman3;
    return solve(1, n, fisherman1, fisherman2, fisherman3, gate1, gate2, gate3);
}