class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> umap;
        int i = 0, j = 0, n = s.size();
        int maxLen = 0;    
        while (j < n) {
            umap[s[j]]++;
            while (umap[s[j]] > 2) {
                umap[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};