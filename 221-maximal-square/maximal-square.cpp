class Solution {
public:
    int n, m, maxSquareSize = 0;
    vector<vector<char>> grid;
    vector<vector<int>> dp;

    int recursive (int r, int c) {
        if (r >= n || c >= m) return 0;
        if (dp[r][c] != -1) return dp[r][c];

        int right = recursive (r, c+1);
        int diagonal = recursive (r+1, c+1);
        int down = recursive (r+1, c);

        if (grid[r][c] == '0') return dp[r][c] = 0;

        int squareSize = 1 + min({right, down, diagonal});
        maxSquareSize = max(maxSquareSize, squareSize);

        return dp[r][c] = squareSize;
    }
 
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        maxSquareSize = 0;
        grid = matrix;
        dp = vector<vector<int>> (n, vector<int>(m, -1));
        
        recursive (0, 0);
        return maxSquareSize * maxSquareSize;
    }
};