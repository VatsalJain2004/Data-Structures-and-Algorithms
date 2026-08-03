class Solution {
public:
    // int count = 0;
    // vector<vector<int>> dp;

    int uniquePaths(int m, int n) {   
        // Not Needed for explorePathsSpaceOptimization => dp = vector<vector<int>>(m, vector<int>(n, -1));
        return explorePathsSpaceOptimization (m, n);
    }

    int explorePathsSpaceOptimization (int m, int n) {
        vector<int> prevDP(n, 0);
        for (int i = 0; i < m; i++) {
            vector<int> curDP(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) curDP[j] = 1;
                else {
                    if (i > 0) curDP[j] += prevDP[j];
                    if (j > 0) curDP[j] += curDP[j-1];
                }
            }
            prevDP = curDP;
        }
        return prevDP[n-1];
    } 
    
    // int explorePathsTabular (int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 0));
    //     dp[0][0] = 1;
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (i == 0 && j == 0) dp[i][j] = 1;
    //             else {
    //                 dp[i][j] = 0;
    //                 if (i > 0) dp[i][j] += dp[i-1][j];
    //                 if (j > 0) dp[i][j] += dp[i][j-1];
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];
    // } 
    

    // int explorePathsMemoization (int m, int n) {
    //     if (m < 0 || n < 0) return 0;
    //     if (m == 0 && n == 0) return 1;

    //     if (dp[m][n] != -1) return dp[m][n];

    //     return dp[m][n] = explorePathsMemoization (m-1, n) + explorePathsMemoization (m, n-1);
    // }
};