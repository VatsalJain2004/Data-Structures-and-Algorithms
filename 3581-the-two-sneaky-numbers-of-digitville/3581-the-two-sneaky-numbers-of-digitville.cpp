class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n, 0);
        for(int it: nums) {
            hash[it] += 1;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int it = hash[i];
            if(it == 3) {
                ans.push_back(i);
                ans.push_back(i);
                return ans;
            }
            else if(it > 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};