// class Solution {
//     int n, m;
//     int solve(int i, int j, string& text1, string& text2) {
//         if(i < 0 || j < 0) {
//             return 0;
//         }

//         if(text1[i] == text2[j]) {
//             return 1 + solve(i-1, j-1, text1, text2);
//         }

//         int p1 = solve(i-1, j, text1, text2);
//         int p2 = solve(i, j-1, text1, text2);

//         return max(p1, p2);
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         this -> n = text1.length(), this -> m = text2.length();

//         if(text1 == text2) {
//             return n;
//         }

//         return solve(n-1, m-1, text1, text2);
//     }
// };



// class Solution {
//     vector<vector<int>> dp;
//     int n, m;
//     int solve(int i, int j, string& text1, string& text2) {
//         if(i < 0 || j < 0) {
//             return 0;
//         }

//         if(dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         if(text1[i] == text2[j]) {
//             // return 1 + solve(i-1, j-1, text1, text2);
//             return dp[i][j] = 1 + solve(i-1, j-1, text1, text2);
//         }

//         int p1 = solve(i-1, j, text1, text2);
//         int p2 = solve(i, j-1, text1, text2);

//         return dp[i][j] = max(p1, p2);
//     }
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         this -> n = text1.length(), this -> m = text2.length();

//         if(text1 == text2) {
//             return n;
//         }
//         this -> dp.resize(n, vector<int>(m, -1));
//         return solve(n-1, m-1, text1, text2);
//     }
// };







class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp;
        int n, m;
        n = text1.length(), m = text2.length();
        dp.resize(n+1, vector<int>(m+1, -1));

        if(text1 == text2) {
            return n;
        }
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        } 
        for(int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                } 
            }
        }
        return dp[n][m];
    }
};