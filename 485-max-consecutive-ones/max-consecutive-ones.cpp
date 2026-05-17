class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0, ones = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            int it = nums[i];
            ones += it;
            if (it == 0) {
                ones = 0;
            }
            if (ones > maxOnes) {
                maxOnes = ones;
            }
        }
        return maxOnes;
    }
};