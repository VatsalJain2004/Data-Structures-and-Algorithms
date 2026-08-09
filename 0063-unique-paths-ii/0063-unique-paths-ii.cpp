class Solution {
public:
    int rows;
    int cols;

    vector<vector<int>> dp2D;
    vector<long long> dp1D;

    int recursive(int row, int col, vector<vector<int>>& obstacleGrid) {
        if (row >= rows || col >= cols)
            return 0;

        if (obstacleGrid[row][col] == 1)
            return 0;

        if (row == rows - 1 && col == cols - 1)
            return 1;

        int down = recursive(row + 1, col, obstacleGrid);
        int right = recursive(row, col + 1, obstacleGrid);

        return down + right;
    }

    int memoization(int row, int col, vector<vector<int>>& obstacleGrid) {
        if (row >= rows || col >= cols)
            return 0;

        if (obstacleGrid[row][col] == 1)
            return 0;

        if (row == rows - 1 && col == cols - 1)
            return 1;

        if (dp2D[row][col] != -1)
            return dp2D[row][col];

        int down = memoization(row + 1, col, obstacleGrid);
        int right = memoization(row, col + 1, obstacleGrid);

        return dp2D[row][col] = down + right;
    }

    int tabulation(vector<vector<int>>& obstacleGrid) {
        dp2D = vector<vector<int>>(
            rows,
            vector<int>(cols, 0)
        );

        if (obstacleGrid[0][0] == 1)
            return 0;

        dp2D[0][0] = 1;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (obstacleGrid[row][col] == 1) {
                    dp2D[row][col] = 0;
                    continue;
                }

                if (row == 0 && col == 0)
                    continue;

                if (row > 0)
                    dp2D[row][col] += dp2D[row - 1][col];

                if (col > 0)
                    dp2D[row][col] += dp2D[row][col - 1];
            }
        }

        return dp2D[rows - 1][cols - 1];
    }

    int spaceOptimization(vector<vector<int>>& obstacleGrid) {
        dp1D = vector<long long>(cols, 0);

        dp1D[0] = 1;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (obstacleGrid[row][col] == 1) {
                    dp1D[col] = 0;
                    continue;
                }

                if (col > 0)
                    dp1D[col] += dp1D[col - 1];
            }
        }

        return dp1D[cols - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();

        return spaceOptimization(obstacleGrid);
    }
};