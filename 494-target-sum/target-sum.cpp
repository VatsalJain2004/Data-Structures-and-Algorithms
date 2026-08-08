class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;

    int targetSumRecursion(int n, int target) {
        if (n < 0)
            return target == 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int add = targetSumRecursion(n - 1, target - nums[n]);
        int subtract = targetSumRecursion(n - 1, target + nums[n]);

        return dp[n][target] = add + subtract;
    }

    int targetSumTabulation(int target) {
        dp = vector<vector<int>>(n + 1,
                                 vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {

                int notTake = dp[i - 1][j];

                int take = 0;

                if (j >= nums[i - 1])
                    take = dp[i - 1][j - nums[i - 1]];

                dp[i][j] = take + notTake;
            }
        }

        return dp[n][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        this->nums = nums;

        int sum = 0;

        for (int& it : nums)
            sum += it;

        if (abs(target) > sum)
            return 0;

        if ((sum + target) % 2 != 0)
            return 0;

        int newTarget = (sum + target) / 2;

        return targetSumTabulation(newTarget);
    }
};