class Solution {
public:
    bool existsInWordList(string& endWord, vector<string>& wordList) {
        for(auto word: wordList) {
            if(word == endWord) {
                return true;
            }
        }
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool check = existsInWordList(endWord, wordList);
        if(!check) {
            return check;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int maxSteps = 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) {
                maxSteps = max(maxSteps, steps);
            } 

            int n = word.size();
            for(int i = 0; i < n; i++) {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if( st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }

        }
        return maxSteps;
    }
};