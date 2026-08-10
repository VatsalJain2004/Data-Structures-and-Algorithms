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

    int longestCommonSubsequence(string s, string t) {
        n = s.length(), m = t.length();    
        this -> s = s;
        this -> t = t;

        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return memoization (n-1, m-1);
    }
};