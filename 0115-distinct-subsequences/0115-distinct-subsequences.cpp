class Solution {
public:
    int n, m;
    string s, t;
    vector<vector<int>> dp;

    int recursive (int i, int j) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (s[i] == t[j])
            return recursive (i-1, j-1) + recursive (i-1, j);
        
        return recursive (i-1, j);
    }
    
    int memoization (int i, int j) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = (memoization (i-1, j-1) + memoization (i-1, j));
        
        return dp[i][j] = memoization (i-1, j);
    }

    int numDistinct(string s, string t) {
        this -> s = s;
        this -> t = t;
        n = s.length(), m = t.length();

        if (m > n) return 0;

        dp = vector<vector<int>>(n, vector<int>(m, -1));

        return memoization (n-1, m-1);
    }
};