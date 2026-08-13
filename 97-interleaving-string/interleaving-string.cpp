class Solution {
public:
    int n, m, l;
    string s, t, r;
    int dp[101][101][201];

    bool recursive (int i, int j, int k) {
        if (k == l && i == n && j == m) return true; 
        if (k >= l) return false;

        if (dp[i][j][k] != -1) return dp[i][j][k];

        bool result = false;
        if (s[i] == r[k]) result = recursive (i+1, j, k+1); 
        if (result) return dp[i][j][k] = result; 

        if (t[j] == r[k]) result = recursive (i, j+1, k+1);
        return dp[i][j][k] = result; 
    }

    bool isInterleave(string s1, string s2, string s3) {
        this -> s = s1;
        this -> t = s2;
        this -> r = s3;

        n = s.length(), m = t.length(), l = r.length();
        if (n+m < l) return false; 

        memset(dp, -1, sizeof(dp));
        return recursive (0, 0, 0);
    }
};