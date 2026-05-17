class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0, ones = 0, n = nums.size();
        for (int& it: nums) {
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