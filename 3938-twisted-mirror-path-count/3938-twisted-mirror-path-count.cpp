class Solution {
public:
    const int M = 1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = 1;
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) { 
                if((i == n-1 && j == m-1) || grid[i][j] == 1) {
                    continue; 
                }

                int rightPath = 0, downPath = 0;
                int curI = i, curJ = j+1, direction = 1;
                while(curI < n && curJ < m) {
                    if(!grid[curI][curJ]) {
                        rightPath = dp[curI][curJ];
                        break;
                    }

                    direction ? curI++ : curJ++;
                    direction = 1 - direction;
                }
                
                curI = i+1, curJ = j, direction = 0;
                while(curI < n && curJ < m) {
                    if(!grid[curI][curJ]) {
                        downPath = dp[curI][curJ];
                        break;
                    }

                    direction ? curI++ : curJ++;
                    direction = 1 - direction;
                }

                dp[i][j] = (rightPath + downPath) % M;
            }
        }
        return dp[0][0];
    }
};