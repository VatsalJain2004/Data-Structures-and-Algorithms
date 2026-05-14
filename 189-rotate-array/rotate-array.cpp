class Solution {
public:
    void reverse(int l, int n, vector<int>& nums) {
        while (l < n) {
            swap(nums[l], nums[n]);
            l += 1;
            n -= 1;
        }
        return;
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(0, n-k-1, nums);   
        reverse(n-k, n-1, nums);   
        reverse(0, n-1, nums);

        return;
    }
};