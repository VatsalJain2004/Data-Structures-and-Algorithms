class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        while (mini != 0) {
            int temp = maxi % mini;
            maxi = mini;
            mini = temp;
        }
        return maxi;
    }
};