class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = n*(n+1)/2, sum1 = 0;
        for (int it: nums) 
            sum1 += it;

        return sum - sum1;
    }
};