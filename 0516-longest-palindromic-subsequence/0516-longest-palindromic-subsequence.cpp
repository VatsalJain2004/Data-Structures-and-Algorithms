class Solution {
public:
    int n;
    string s;
    vector<vector<int>> dp;

    int recursive (int i, int j) {
        if (i > j) return 0;
        if (i == j) {
            return 1;
        }
        else if (s[i] == s[j]) {
            return 2 + recursive (i+1, j-1);
        }
        else {
            return max(recursive(i+1, j), recursive (i, j-1));
        }
    }
    
    int memoization (int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (i == j) return 1;
        
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + memoization (i+1, j-1);
        }
        else {
            return dp[i][j] = max(memoization(i+1, j), memoization (i, j-1));
        }
    }

    int longestPalindromeSubseq(string s) {
        this -> s = s;
        n = s.length();

        dp = vector<vector<int>>(1000, vector<int>(1000, -1));

        return memoization (0, n-1);    
    }
};