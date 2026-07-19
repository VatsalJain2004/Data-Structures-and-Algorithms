class Solution {
public:
    string removeDuplicateLetters(string s) {
                vector<int> lastIndex(26);
        vector<bool> used(26, false);
        string res = "";
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]-'a'] = i;
        }    

        for (int i = 0; i < n; i++) {
            int idx = s[i]-'a';

            if (used[idx]) {
                continue;
            }
            while (res.length() > 0 && res.back() > s[i] && lastIndex[res.back()-'a'] > i) {
                used[res.back()-'a'] = false;
                res.pop_back();
            } 
            res += s[i]; 
            used[idx] = true; 
        }

        return res;
    }
};