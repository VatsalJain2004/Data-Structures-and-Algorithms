class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int smallest = INT_MAX, largest = INT_MIN;
        for (int& it: nums) {
            smallest = min(smallest, it);
            largest = max(largest, it);
            uset.insert(it);
        }

        int maxLen = 0;
        for (int it: uset) {
            int len = 0; 
            if (uset.find(it+1) == uset.end()) {
                while (uset.find(it) != uset.end()) {
                    it -= 1;
                    len += 1;
                }
            }   
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};