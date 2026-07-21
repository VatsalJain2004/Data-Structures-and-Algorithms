class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, countOfZero = 0;
        for (int& it: nums) {
            if (!it) {
                countOfZero += 1;
            }
            else {
                product *= it;
            }
        }

        vector<int> ans;
        if (countOfZero > 1) {
            return vector<int>(nums.size(), 0);
        }
        else if (countOfZero == 1) {
            for (int& it: nums) {
                ans.push_back(it == 0 ? product : 0);
            }
        }
        else {
            for (int& it: nums) {
                ans.push_back(product / it);
            }
        }

        return ans;
    }
};