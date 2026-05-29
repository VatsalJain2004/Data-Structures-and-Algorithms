class Solution {
public:
    int minElement(vector<int>& nums) {
        int minSum = INT_MAX;
        for (int& it: nums) {
            int sum = 0;
            while (it) {
                sum += it % 10;
                it /= 10;
            }

            minSum = min(minSum, sum);
        }
        return minSum;
    }
};