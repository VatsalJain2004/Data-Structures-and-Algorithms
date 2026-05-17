class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1, 0);
        for (int it: nums) {
            hash[it] += 1;
        }

        for (int i = 0; i < n+1; i++) {
            if (hash[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};