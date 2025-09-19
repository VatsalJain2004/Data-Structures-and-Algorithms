class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n <= 60) {
            long long freq = 1, sum = 0;
            for(int i = 0; i < n; i++) {
                sum += nums[i]*freq;
                freq = freq*(n-1-i)/(i+1);
            }
            sum %= 10;
            return sum;
        }
        else {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n - i - 1; j++) {
                    nums[j] = (nums[j] + nums[j + 1]) % 10;
                }
            }
            return nums[0];
        }
        return -1;
    }
};