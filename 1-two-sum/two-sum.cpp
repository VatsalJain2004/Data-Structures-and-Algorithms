class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++) {
            if (umap.count(target-nums[i])) {
                return {umap[target-nums[i]], i};
            }
            umap[nums[i]] = i;
        }
        return {};
    }
};