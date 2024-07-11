// maxSum=5000;

class Solution
{
public:
    int n;
    int f(int i, int dif, vector<int> &rods, vector<vector<int>> &dp)
    {

        if (i >= n)
        {

            if (dif == 0)
            {
                return 0;
            }

            return -1e5;
        }

        if (dp[i][dif + 5001] != -1)
        {
            return dp[i][dif + 5001];
        }

        // 1 take
        int a = rods[i] + f(i + 1, dif + rods[i], rods, dp);

        // 2 take
        int b = rods[i] + f(i + 1, dif - rods[i], rods, dp);

        // no-take
        int c = f(i + 1, dif, rods, dp);

        return dp[i][dif + 5001] = max(a, max(b, c));
    }

    int tallestBillboard(vector<int> &rods)
    {
        n = rods.size();

        vector<vector<int>> dp(22, vector<int>(10002, -1));
        int ans = f(0, 0, rods, dp);

        return ans / 2;
    }
};