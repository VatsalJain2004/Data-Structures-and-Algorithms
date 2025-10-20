class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int prev2 = 0, prev1 = 1;

        for(int i = 2; i <= n; i++){
            int cur = prev1 + prev2;
            prev2 = prev1, prev1 = cur;
        }
        return prev1;
    }
};



// class Solution {
// public:
//     int solve(int n, vector<int>& dp){
//         if(n <= 1){
//             return dp[n] = n;
//         }

//         if(dp[n] != -1)
//             return dp[n];
        
//         return dp[n] = solve(n-1, dp) + solve(n-2, dp);
//     }

//     int fib(int n) {
//         vector<int> dp(n+1, -1);
//         solve(n, dp);
//         return dp[n];
//     }
// };