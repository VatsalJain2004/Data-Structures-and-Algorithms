class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min (dfs (n-1, cost, dp), dfs(n-2, cost, dp));
    }

    int dfs (int n, vector<int>& cost, vector<int>& dp) {
        if (n <= 1) return dp[n] = cost[n];
        if (dp[n] != -1) return dp[n];

        return dp[n] = cost[n] + min (dfs (n-1, cost, dp), dfs (n-2, cost, dp));
    }
};