class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;

    int recursive (int i, int prev) {
        if (i < 0) return 0;

        int pick = 0;
        if (prev > nums[i]) pick = 1 + recursive (i-1, nums[i]);
        int notPick = recursive (i-1, prev);
        
        return max(pick, notPick);
    }

    int memoization (int i, int prev) {
        if (i < 0) return 0;
        if (prev != -1 && dp[i][prev] != -1) return dp[i][prev];

        int pick = 0;
        if (prev == -1 || nums[prev] > nums[i]) pick = 1 + memoization (i-1, i);
        int notPick = memoization (i-1, prev);
        
        return prev != -1 ? dp[i][prev] = max(pick, notPick) : max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        this -> nums = nums;
        n = nums.size();

        dp = vector<vector<int>> (2500, vector<int>(2500, -1));

        return memoization (n-1, -1);
    }
};