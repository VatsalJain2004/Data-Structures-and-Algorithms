class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        vector<int> ans;
        for (int& it: nums) {
            right += it;
        }

        for (int i = 0; i < n; i++) {
            left += nums[i];
            ans.push_back(abs(left-right));
            right -= nums[i];
        }
        return ans;
    }
};