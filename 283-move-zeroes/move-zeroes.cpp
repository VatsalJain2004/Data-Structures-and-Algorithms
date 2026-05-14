class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int left = 0, right = 0; right < n; right++) {
            if (nums[right]) {
                swap(nums[left++], nums[right]);
            }
        }
        return;
    }
};