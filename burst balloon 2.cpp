#include <bits/stdc++.h>
using namespace std;

int solve(int left,int right,vector<int> nums){
    if(left>right)
        return 0;
    if(dp[left][right]!=-1)
        return dp[left][right];
    int ans = 0;
    for (int i = left; i <= right;i++){
        ans = max(ans, nums[left - 1] * nums[i] * nums[right + 1] + solve(left, i - 1, nums) + solve(i + 1, right, nums));
    }
    return dp[left][right]=ans;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,-1))
    return solve(1,n,nums)
}