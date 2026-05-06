class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int even = 0, odd = 0, n = nums.size();
        vector<int> ans(n, 0);
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] % 2) {
                odd += 1;
            }
            else {
                even += 1;
            }

            ans[i] = nums[i] % 2 ? even : odd;
        }  
        return ans;
    }   
};