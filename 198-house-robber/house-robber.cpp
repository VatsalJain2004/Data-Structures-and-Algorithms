class Solution {
public:
    int n;
    vector<int> dp;
    vector<int> nums;

    int robOrLeaveMemoization (int i, int moneyRobbed) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];
        if (dp[i] != -1) return dp[i];

        int rob = nums[i] + robOrLeaveMemoization (i-2, moneyRobbed + nums[i]);
        int leave = robOrLeaveMemoization (i-1, moneyRobbed);

        return dp[i] = max({rob, leave});
    }

    int robOrLeaveTabulation () {
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int rob = nums[i] + (i > 1 ? dp[i-2] : 0);
            int leave = (i > 0) ? dp[i-1] : 0;
            dp[i] = max({rob, leave});
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        n = nums.size();
        dp = vector<int>(n, -1);
        this -> nums = nums;
        return robOrLeaveMemoization(n-1, 0);    
    }
};