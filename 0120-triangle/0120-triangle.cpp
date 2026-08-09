class Solution {
public:

    long long recursion(vector<vector<int>>& triangle, int i, int j, int n){
        if(i == n-1)
            return triangle[i][j];
        
        int one = recursion(triangle, i+1, j, n);
        int two = recursion(triangle, i+1, j+1, n);
        
        return min(one, two) + triangle[i][j];
    }

    int memoization (vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j, int n){
        if(i == n-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];
        
        int one = memoization(triangle, dp, i+1, j, n);
        int two = memoization(triangle, dp, i+1, j+1, n);
        
        return dp[i][j] = min(one, two) + triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        vector<vector<int>> dp = triangle;
        for(int i = 0; i < n; i++){
            int m = triangle[i].size();
            for(int j = 0; j < m; j++){
                dp[i][j] = -1;
            }
        }
        
        return tabulation(triangle);
    }

    int tabulation(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int j = 0; j < triangle[n-1].size(); j++)
            dp[n-1][j] = triangle[n-1][j];


        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int one = dp[i+1][j];        
                int two = dp[i+1][j+1];

                dp[i][j] = min(one, two) + triangle[i][j];        
            }
        }
        
        return dp[0][0];
    }

    int spaceOptimization(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> prev(n);
        for(int j = 0; j < triangle[n-1].size(); j++)
            prev[j] = triangle[n-1][j];


        for(int i = n-2; i >= 0; i--){
            vector<int> cur(n);
            for(int j = i; j >= 0; j--){
                int one = prev[j];        
                int two = prev[j+1];

                cur[j] = min(one, two) + triangle[i][j];        
            }
            prev = cur;
        }
        
        return prev[0];
    }
};