class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int ones = 0, j = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                ones++;

            if (ones == k) {
                while (j <= i && s[j] == '0')
                    j++;

                string cur = s.substr(j, i - j + 1);

                if (ans.empty() || cur.length() < ans.length() ||
                    (cur.length() == ans.length() && cur < ans)) {
                    ans = cur;
                }

                ones--;
                j++;
            }
        }

        return ans;
    }
};
