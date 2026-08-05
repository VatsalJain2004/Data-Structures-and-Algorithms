class Solution {
public:
    vector<int> dp;
    vector<int> nums;

    int n;
    int limit;

    int robRecursive (int i) {
        if (i < limit) return 0;
        if (i == limit) return dp[i] = nums[i];

        int rob = nums[i] + robRecursive (i-2);
        int leave = robRecursive (i-1);

        return max(rob, leave);
    }

    int robMemoization (int i) {
        if (i < limit) return 0;
        if (i == limit) return dp[i] = nums[i];

        if (dp[i] != -1) return dp[i];

        int rob = nums[i] + robMemoization (i-2);
        int leave = robMemoization (i-1);

        return dp[i] = max(rob, leave);
    }

    // int robTabulation ()

    int rob(vector<int>& nums) {
        this -> nums = nums;
        n = nums.size();
        if (n == 1) return nums[0];

        dp = vector<int>(n, -1);
        limit = 0;
        int zeroIndexStart = robMemoization(n-2);

        dp = vector<int>(n, -1);
        limit = 1;
        int oneIndexStart = robMemoization(n-1);

        return max(zeroIndexStart, oneIndexStart);    
    }
};