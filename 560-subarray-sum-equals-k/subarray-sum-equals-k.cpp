class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> numsMap;
        numsMap[0] = 1;
        int subarrays = 0, prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix += arr[i];
            if (numsMap.find(prefix - k) != numsMap.end()) {
                subarrays += numsMap[prefix - k];
            }
            numsMap[prefix]++;
        }

        return subarrays;
    }
};