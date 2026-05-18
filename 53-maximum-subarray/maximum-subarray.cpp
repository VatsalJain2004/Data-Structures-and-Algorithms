class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        for (int& it: nums) {
            sum += it;
            maxSum = max(maxSum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }   
        return maxSum;
    }
};