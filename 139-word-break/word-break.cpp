class Solution {
public:
    int n;
    
    string s;
    unordered_set<string> dictMap;
    vector<int> dp;

    bool tabulation () {
        return dp[n-1];
    }

    bool memoization (int i) {
        if (i == n) return true;
        if (dp[i] != -1) return dp[i]; 

        for (int j = i; j < n; j++) {
            string word = s.substr(i, j-i+1);
            if (dictMap.count(word)) {
                if (memoization (j+1)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }

    bool recursive (int i) {
        if (i == n) return true;

        for (int j = i; j < n; j++) {
            string word = s.substr(i, j-i+1);
            if (dictMap.count(word) && recursive (j+1)) {
                return true;
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dictMap = unordered_set<string> (wordDict.begin(), wordDict.end());
        this -> s = s;
        n = s.length();
        dp = vector<int> (n, -1);

        return memoization (0);
    }   
};