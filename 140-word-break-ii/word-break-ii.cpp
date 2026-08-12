class Solution {
public:
    int n;

    string s;
    vector<string> ans;
    unordered_set<string> dictSet;

    void recursive (int i, string sentence) {
        if (i > n) return;
        if (i == n) {
            sentence.pop_back();
            ans.push_back(sentence);
            return;
        }

        for (int j = i; j < n; j++) {
            sentence += s[j];
            if (dictSet.count(s.substr(i, j-i+1))) {
                sentence += ' ';
                recursive (j+1, sentence);
                sentence.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this -> s = s;
        dictSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        n = (this -> s).length();

        recursive(0, "");

        return ans;
    }
};