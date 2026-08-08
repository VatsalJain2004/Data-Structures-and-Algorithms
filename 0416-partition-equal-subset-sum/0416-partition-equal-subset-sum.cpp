class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<bool>> dp;

    bool canPartitionRecursion (int n, int target) {
        if (n < 0) return false;
        if (target == 0) return dp[n][target] = true;

        if (dp[n][target] != false) return dp[n][target];

        bool take = false;
        if (target >= nums[n])
            take = canPartitionRecursion (n-1, target-nums[n]);

        bool notTake = canPartitionRecursion (n-1, target);

        return dp[n][target] = (take || notTake);
    }

    bool canPartitionTabulation(int target) {
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (dp[i][j]) continue;

                bool notTake = dp[i-1][j];
                bool take = false;
                if (j >= nums[i-1])
                    take = dp[i-1][j-nums[i-1]];

                dp[i][j] = take || notTake;
            }
        }

        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        this -> nums = nums;
     
        int sum = 0, target = 0;
        for (int& it: nums) sum += it;
        if (sum % 2) return false;

        target = sum / 2;

        this -> dp = vector<vector<bool>>(n+1, vector<bool>(target+1, false));

        return canPartitionTabulation (target);
    }
};