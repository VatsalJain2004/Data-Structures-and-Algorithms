class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), minCost = INT_MAX;
        vector<int> dp(n+1, -1);
        dp[0] = cost[0], dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min (dp[n-1], dp[n-2]);
    }

    int dfs (int n, vector<int>& cost, vector<int>& dp) {
        if (n <= 1) return dp[n] = cost[n];
        if (dp[n] != -1) return dp[n];

        return dp[n] = cost[n] + min (dfs (n-1, cost, dp), dfs (n-2, cost, dp));
    }
};