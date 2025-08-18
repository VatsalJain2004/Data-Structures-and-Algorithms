// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         // unordered_set<string> st(wordList.begin(), wordList.end());
//         // st.erase(beginWord);
//         // if(st.find(endWord) == st.end()) {
//         //     return {};
//         // }
        
//         // vector<vector<string>> transformationList;
//         // int level = 0;
//         // vector<string> usedOnLevel;
//         // usedOnLevel.push_back(beginWord);
//         // queue<vector<string>> q;
//         // q.push({beginWord});
//         // while(!q.empty()) {
//         //     vector<string> wordsArray = q.front();
//         //     q.pop();
//         //     if(wordsArray.size() > level) {
//         //         level += 1;
//         //         for(auto it: usedOnLevel) {
//         //             st.erase(it);
//         //         }
//         //     }

//         //     string word = wordsArray.back();
//         //     if(word == endWord) {
//         //         if(!transformationList.size() || transformationList[0].size() == wordsArray.size()) {
//         //             transformationList.push_back(wordsArray);
//         //         }
//         //     int n = word.size();
//         //     }
//         //     for(int i = 0; i < n; i++) {
//         //         char original = word[i];
//         //         for(char c = 'a'; c <= 'z'; c++) {
//         //             word[i] = c;
//         //             if(st.find(word) != st.end()) {
//         //                 wordsArray.push_back(word); 
//         //                 q.push(wordsArray);
//         //                 usedOnLevel.push_back(word);
//         //                 wordsArray.pop_back(); 
//         //             }
//         //         }
//         //         word[i] = original;
//         //     }

//         // }
//         // return transformationList;
//         vector<vector<string>> ans;
//         unordered_set<string> dict(wordList.begin(),wordList.end());
//         if (dict.find(endWord) == dict.end()) return ans;
        
//         queue<vector<string>>q;
//         q.push({beginWord});
//         dict.erase(beginWord);
        
//         while (!q.empty()){
//             int s = q.size();
//             vector<string>wordsUsed;
//             for (int i = 0; i < s; i++){
//                 vector<string>path = q.front();
//                 string word = q.front().back();
//                 q.pop();
                
//                 if (word == endWord){
//                     ans.push_back(path);
//                     continue;
//                 }
//                 for (int i = 0; i < word.size(); i++){
//                     char original = word[i];
//                     for (char c = 'a'; c <= 'z'; c++) {
//                         word[i] = c;
//                         if ( dict.find(word) != dict.end() ) { 
//                             path.push_back(word);
//                             q.push(path);
//                             wordsUsed.push_back(word);
//                             path.pop_back();
//                         }
//                     }
//                     word[i] = original;
//                 }
//             }
//             for(auto it : wordsUsed) dict.erase(it);
//         } 
//         return ans;
//     }
// };


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> depthMap;
        vector<vector<string>> ans;
        
        // BFS to find the shortest path
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        depthMap[beginWord] = 1;
        wordSet.erase(beginWord);
        
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = depthMap[word];
            if (word == endWord) break;
            for (int i = 0; i < word.size(); ++i) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    word[i] = ch;
                    if (wordSet.count(word)) {
                        q.push(word);
                        wordSet.erase(word);
                        depthMap[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        
        // DFS to find all paths
        if (depthMap.count(endWord)) {
            vector<string> seq = {endWord};
            dfs(endWord, beginWord, seq, depthMap, ans);
        }
        
        return ans;
    }
    
private:
    void dfs(string word, string beginWord, vector<string>& seq, unordered_map<string, int>& depthMap, vector<vector<string>>& ans) {
        if (word == beginWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int steps = depthMap[word];
        for (int i = 0; i < word.size(); ++i) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                word[i] = ch;
                if (depthMap.count(word) && depthMap[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, beginWord, seq, depthMap, ans);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
};