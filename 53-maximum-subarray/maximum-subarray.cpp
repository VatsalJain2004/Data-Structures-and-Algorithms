class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sum = 0;
        for (int& it: nums) {
            sum = max(it, sum + it);
            maxSum = max(maxSum, sum);
        }   
        return maxSum;
    }
};