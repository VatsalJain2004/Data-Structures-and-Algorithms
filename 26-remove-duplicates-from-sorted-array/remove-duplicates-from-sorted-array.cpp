class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1, right = 1;
        int n = nums.size();

        while (right < n) {
            if (nums[left-1] < nums[right]) {
                nums[left] = nums[right];
                left += 1; 
            }
            right += 1;
        }
        return left;
    }
};