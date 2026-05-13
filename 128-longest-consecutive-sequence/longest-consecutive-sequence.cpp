class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs(nums.begin(), nums.end());

        int longest = 0, currCount = 0;
        for (int ele : hs) {
            int currEle = ele;
            currCount = 1;

            if (hs.find(currEle - 1) == hs.end()) {
                while (hs.find(currEle + 1) != hs.end()) {
                    currCount++;
                    currEle++;
                }

                longest = max(longest, currCount);
            }
        }

        return longest;
    }
};