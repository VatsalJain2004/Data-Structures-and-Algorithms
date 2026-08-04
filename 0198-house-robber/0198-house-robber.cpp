class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int minus1 = nums[0], minus2 = 0;
        for(int i = 1; i < n; i++) {
            int p = nums[i];
            if(i > 1) {
                p += minus2;
            }
            int np = minus1;
            int cur = max(p, np);
            minus2 = minus1;
            minus1 = cur;
        }
        return minus1;
    }
};