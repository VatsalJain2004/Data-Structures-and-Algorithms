class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<int>> dp;

    int recursive (int r, int c) {
        if (r < 0 || c < 0) return INT_MAX;
        if (r == 0 && c == 0) return grid[0][0];

        return grid[r][c] + min (recursive(r-1, c), recursive(r, c-1));
    }

    int memoization (int r, int c) {
        if (r < 0 || c < 0) return 1e9;
        if (r == 0 && c == 0) return dp[r][c] = grid[0][0];
        if (dp[r][c] != -1) return dp[r][c];

        return dp[r][c] = grid[r][c] + min (memoization(r-1, c), memoization(r, c-1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        this -> grid = grid;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return memoization (m-1, n-1);
    }
};