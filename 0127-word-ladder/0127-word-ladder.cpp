class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        if(st.find(endWord) == st.end()) {
            return 0;
        }
        
        int maxSteps = 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
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