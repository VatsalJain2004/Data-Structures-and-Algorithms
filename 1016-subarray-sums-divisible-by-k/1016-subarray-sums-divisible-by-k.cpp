// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size(), count = 0;
//         for(int i = 0; i < n; i++) {
//             int sum = 0;
//             for(int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if(sum % k == 0) {
//                     count += 1;
//                 }
//             }
//         }
//         return count;
//     }
// };

// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         unordered_map<int, int> umap;
//         umap[0] = 1; // why ? take nothing from the array sum == 0 and 0 % k
//         == 0, hence count + 1

//         int n = nums.size(), count = 0;
//         long long sum = 0;
//         for(int num: nums) {
//             sum += num;
//             int rem = sum % k;

//             if(rem < 0) {
//                 rem += k;
//             }

//             if(umap.find(rem) != umap.end()) {
//                 count += umap[rem];
//             }
//             umap[rem] += 1;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> remfreq(k, 0);
        remfreq[0] = 1;
        
        long long prefsum = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            prefsum += nums[i];
            int r = ((prefsum % k) + k) % k;
            count += remfreq[r];
            remfreq[r]++;   
        }
        return count;
    }
};