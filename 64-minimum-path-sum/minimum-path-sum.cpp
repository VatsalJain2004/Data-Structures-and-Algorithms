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

    int tabulation () {
        dp = vector<vector<int>>(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for (int c = 1; c < n; c++) {
            dp[0][c] = grid[0][c] + dp[0][c - 1];
        }
        
        for (int r = 1; r < m; r++) {
            dp[r][0] = grid[r][0] + dp[r - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min (dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        this -> grid = grid;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return tabulation ();
    }
};