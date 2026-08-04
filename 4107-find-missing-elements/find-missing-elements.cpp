class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        unordered_set<int> uset;
        for (int& it: nums) {
            uset.insert(it);
            minNum = min(minNum, it);
            maxNum = max(maxNum, it);
        }

        vector<int> missingNumbers;
        for (int i = minNum; i <= maxNum; i++) {
            if (uset.find(i) == uset.end()) {
                missingNumbers.push_back(i);
            }
        }
        return missingNumbers;
    }
};