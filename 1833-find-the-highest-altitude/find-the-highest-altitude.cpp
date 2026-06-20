class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size()+1;
        
        int sum = 0, maxAlt = 0;
        for(int i = 1; i < n; i++){
            sum += gain[i-1];
            maxAlt = max(maxAlt, sum);
        }
        return maxAlt;
    }
};