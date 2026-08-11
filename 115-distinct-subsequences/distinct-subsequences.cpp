class Solution {
public:
    int n, m;
    string s, t;
    vector<vector<int>> dp;

    int recursive (int i, int j) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        int notPick = recursive (i-1, j);

        if (s[i] == t[j])
            return recursive (i-1, j-1) + notPick;

        return notPick;
    }
    
    int memoization (int i, int j) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) return dp[i][j] = (memoization (i-1, j-1) + memoization (i-1, j));
        
        return dp[i][j] = memoization (i-1, j);
    }

    int tabulation () {
        vector<vector<double>> ldp(n+1, vector<double>(m+1, 0));

        for (int i = 0; i <= n; i++) ldp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) {
                    ldp[i][j] = ldp[i-1][j-1] + ldp[i-1][j];
                }
                else {
                    ldp[i][j] = ldp[i-1][j];
                }
            }
        }

        return (int)ldp[n][m];
    }

    int numDistinct(string s, string t) {
        this -> s = s;
        this -> t = t;
        n = (this -> s).length(), m = (this -> t).length();

        if (m > n || m == 0 || n == 0) return 0;

        return tabulation ();
    }
};