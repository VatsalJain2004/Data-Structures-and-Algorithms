class Solution {
public:
    int n, m, maxSquareSize = 0;
    vector<vector<char>> grid;
    vector<vector<int>> dp;

    int memoization(int r, int c) {
        if (r >= n || c >= m)
            return 0;
        if (dp[r][c] != -1)
            return dp[r][c];

        int right = memoization(r, c + 1);
        int diagonal = memoization(r + 1, c + 1);
        int down = memoization(r + 1, c);

        if (grid[r][c] == '0')
            return dp[r][c] = 0;

        int squareSize = 1 + min({right, down, diagonal});
        maxSquareSize = max(maxSquareSize, squareSize);

        return dp[r][c] = squareSize;
    }

    int tabulation() {
        dp = vector<vector<int>>(n, vector<int>(m, 0));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '1') {
                    int right = (c - 1 >= 0) ? dp[r][c - 1] : 0;
                    int down = (r - 1 >= 0) ? dp[r - 1][c] : 0;
                    int diagonal =
                        (r - 1 >= 0 && c - 1 >= 0) ? dp[r - 1][c - 1] : 0;

                    dp[r][c] = 1 + min({right, down, diagonal});

                    maxSquareSize = max(maxSquareSize, dp[r][c]);
                }
            }
        }

        return maxSquareSize * maxSquareSize;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        maxSquareSize = 0;
        grid = matrix;
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return tabulation();
    }
};