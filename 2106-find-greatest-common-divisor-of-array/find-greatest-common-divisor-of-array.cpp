class Solution {
public:
    int gcdFunction (int a, int b) {
        return b == 0 ? a : gcdFunction(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        int ans = gcdFunction(minNum, maxNum);     
        return ans;
    }
};