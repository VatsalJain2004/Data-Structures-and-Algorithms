class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0], count = 0;
        for (int& it : nums) {
            count += it == val ? 1 : -1;
            if (count < 0) {
                count = 0;
                val = it;
            }
        }
        return val;
    }
};