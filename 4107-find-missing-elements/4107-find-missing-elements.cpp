class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        unordered_map<int, int> umap;
        for(int it: nums) {
            umap[it] += 1;
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        vector<int> missingNumbers;
        for(int i = mini; i <= maxi; i++) {
            if(umap.find(i) == umap.end()) {
                missingNumbers.push_back(i);
            }
        }
        return missingNumbers;
    }
};