class Solution {
public:
    int n;
    vector<int> dp;
    int robOrLeave (int i, int moneyRobbed, vector<int>& nums) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        int rob = nums[i] + robOrLeave (i-2, moneyRobbed + nums[i], nums);
        int leave = robOrLeave (i-1, moneyRobbed, nums);

        return dp[i] = max({rob, leave});
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        dp = vector<int>(n, -1);
        return robOrLeave(n-1, 0, nums);    
    }
};