class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;

    bool canPartitionRecursion (int n, int target) {
        if (n < 0) return false;
        if (target == 0) return true;

        if (dp[n][target] != -1) return dp[n][target];

        bool take = false;
        if (target >= nums[n])
            take = canPartitionRecursion (n-1, target-nums[n]);

        bool notTake = canPartitionRecursion (n-1, target);

        return dp[n][target] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        this -> nums = nums;
     
        int sum = 0;
        for (int& it: nums) sum += it;
        if (sum % 2) return false;

        this -> dp = vector<vector<int>>(n+1, vector<int>((sum/2) + 1, -1));

        return canPartitionRecursion (n-1, sum / 2);
    }
};