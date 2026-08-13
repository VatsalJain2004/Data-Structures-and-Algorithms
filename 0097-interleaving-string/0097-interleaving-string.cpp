class Solution {
public:
    int n, m, l;
    string s, t, r;
    int dp3[101][101][202];
    int dp2[101][101];

    bool recursive3D (int i, int j, int k) {
        if (k == l && i == n && j == m) return true; 
        if (k >= l) return false;

        if (dp3[i][j][k] != -1) return dp3[i][j][k];

        bool result = false;
        if (s[i] == r[k]) result = recursive3D (i+1, j, k+1); 
        if (result) return dp3[i][j][k] = result; 

        if (t[j] == r[k]) result = recursive3D (i, j+1, k+1);
        return dp3[i][j][k] = result; 
    }
    
    bool recursive2D (int i, int j) {
        if (i+j == l && i == n && j == m) return true; 
        if (i+j >= l) return false;

        if (dp2[i][j] != -1) return dp2[i][j];

        bool result = false;
        if (s[i] == r[i+j]) result = recursive2D (i+1, j); 
        if (result) return dp2[i][j] = result; 

        if (t[j] == r[i+j]) result = recursive2D (i, j+1);
        return dp2[i][j] = result; 
    }

    bool isInterleave(string s1, string s2, string s3) {
        this -> s = s1;
        this -> t = s2;
        this -> r = s3;

        n = s.length(), m = t.length(), l = r.length();
        if (n+m < l) return false; 

        memset(dp2, -1, sizeof(dp2));
        memset(dp3, -1, sizeof(dp3));
        return recursive2D (0, 0);
    }
};