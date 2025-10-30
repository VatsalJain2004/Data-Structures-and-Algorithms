// class Solution {
// public:
//     int solve(int ind, int n){
//         if(ind > n)
//             return 0;
//         if(ind == n)
//             return 1;
        
//         int count = solve(ind+1, n) + solve(ind+2, n);
//         return count;
//     }

//     int climbStairs(int n) {
//         if(n <= 2)
//             return n;
        
//         int count = 0;

//         return solve(0, n);
//     }
// };






// class Solution {
// public:
//     int solve(int ind, int n, vector<int>& dp){
//         if(ind > n)
//             return 0;
//         if(ind == n)
//             return 1;
//         if(dp[ind] != -1)
//             return dp[ind];
        
//         int count = solve(ind+1, n, dp) + solve(ind+2, n, dp);
//         return dp[ind] = count;
//     }

//     int climbStairs(int n) {
//         if(n <= 2)
//             return n;
//         vector<int> dp(n+1, -1);

//         int count = 0;

//         return solve(0, n, dp);
//     }
// };









class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1)
            return n;
        
        int prev1 = 1, prev2 = 1;
        int count = prev1 + prev2;

        for(int i = 2; i <= n; i++){
            count = prev2 + prev1;
            prev2 = prev1;    
            prev1 = count;
        }

        return count;
    }
};