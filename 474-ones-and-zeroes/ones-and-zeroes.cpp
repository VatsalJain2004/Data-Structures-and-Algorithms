class Solution {
public: 
    int len;
    int count = 0;
    vector<string> strs;
    vector<vector<int>> freq; 
    vector<vector<vector<int>>> dp;

    void buildFrequencyArray () {
        freq.clear();

        for (string& s: strs) {
            int zeroes = 0, ones = 0;
            for (char c: s) {
                c == '0' ? zeroes += 1 : ones += 1;
            }

            freq.push_back({zeroes, ones});
        } 

        return;
    }

    int findMaxFormRecursive (int len, int zeroes, int ones, int subsetLength) {
        if (len < 0) return 0;
        if (dp[len][zeroes][ones] != -1) return dp[len][zeroes][ones];
    
        int zeroCount = freq[len][0], oneCount = freq[len][1];
        int take = 0, notTake = 0;
        if (zeroCount <= zeroes && oneCount <= ones) {
            take = 1 + findMaxFormRecursive (len-1, zeroes - zeroCount, ones - oneCount, subsetLength + 1);
        } 
        notTake = findMaxFormRecursive (len-1, zeroes, ones, subsetLength);

        return dp[len][zeroes][ones] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int zeroes, int ones) {
        this -> len = strs.size();
        this -> strs = strs;
        this -> count = 0;
        this -> dp = vector<vector<vector<int>>> (len+1, vector<vector<int>>(zeroes+1, vector<int>(ones+1, -1)));

        buildFrequencyArray();

        return findMaxFormRecursive (len-1, zeroes, ones, 0);
    }
};