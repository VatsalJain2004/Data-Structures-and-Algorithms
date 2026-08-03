class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        // memoization...
        // dfs(n-1) --> prev, dfs(n-2) --> prev'prev
        int prev1 = 1, prev2 = 1, count = prev1 + prev2;
        for (int i = 2; i <= n; i++) {
            count = prev1 + prev2;
            prev2 = prev1;
            prev1 = count;
        }

        return prev1;
    }

    // dfs solution
    int dfs(int n, vector<int>& dp) {
        if (n <= 1) return dp[n] = 1;
        if (dp[n] != -1) return dp[n];

        return dp[n] = dfs (n-1, dp) + dfs (n-2, dp);
    }
};