class Solution {
public:
    int n, m;
    string s, t;

    vector<vector<int>> dp;

    int recursive (int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (s[i] == t[j]) return 1 + recursive (i-1, j-1);

        return max(recursive (i-1, j), recursive (i, j-1));
    }

    int memoization (int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) return dp[i][j] =  1 + memoization (i-1, j-1);

        return dp[i][j] = max(memoization (i-1, j), memoization (i, j-1));
    }

    int tabulation () { 
        dp = vector<vector<int>>(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j]) {
                    continue;
                }
                if (s[i] == t[j]) {
                    dp[i][j] = 1 + ((i > 0 && j > 0) ? dp[i-1][j-1] : 0);
                }
                else {
                    dp[i][j] = max((i > 0 ? dp[i-1][j] : 0), (j > 0 ? dp[i][j-1] : 0));
                }
            }
        }

        return dp[n-1][m-1];
    }

    int spaceOptimization () { 
        vector<int> prev(m+1, 0);
        for (int i = 0; i < n; i++) {
            vector<int> cur(m+1, 0);
            for (int j = 0; j < m; j++) {
                if (cur[j]) {
                    continue;
                }
                if (s[i] == t[j]) {
                    cur[j] = 1 + ((i > 0 && j > 0) ? prev[j-1] : 0);
                }
                else {
                    cur[j] = max((i > 0 ? prev[j] : 0), (j > 0 ? cur[j-1] : 0));
                }
            }
            prev = cur;
        }

        return prev[m-1];
    }

    int longestCommonSubsequence(string s, string t) {
        n = s.length(), m = t.length();    
        this -> s = s;
        this -> t = t;

        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return spaceOptimization();
    }
};