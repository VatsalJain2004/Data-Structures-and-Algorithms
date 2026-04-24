class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        vector<int> need(256, 0);
        for (char c : t) {
            need[(unsigned char)c]++;
        }

        int left = 0;
        int required = t.length();
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            if (need[(unsigned char)ch] > 0) {
                required--;
            }

            need[(unsigned char)ch]--;

            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                need[(unsigned char)leftChar]++;

                if (need[(unsigned char)leftChar] > 0) {
                    required++;
                }

                left++;
            }
        }

        return minLen == INT_MAX
            ? ""
            : s.substr(start, minLen);
    }
};