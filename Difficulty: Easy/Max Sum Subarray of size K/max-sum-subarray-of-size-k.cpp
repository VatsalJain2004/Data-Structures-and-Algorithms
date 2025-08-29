class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int ms = 0;
        for(int i = 0; i < k; i++) {
            ms += arr[i];
        }
        
        int ws=ms;
        for(int i = k; i < n; i++) {
            ws += arr[i] - arr[i-k];
            ms = max(ms, ws);
        }
        
        return ms;
    }
};

