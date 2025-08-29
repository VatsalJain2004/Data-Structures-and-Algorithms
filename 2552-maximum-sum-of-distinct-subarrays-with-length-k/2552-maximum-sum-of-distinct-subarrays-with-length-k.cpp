// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         unordered_set<int> uset;
//         long long sum = 0, maxSum = 0;
//         int i = 0, j = 0;
//         while(j < n) {
//             while(uset.count(nums[j])) {
//                 uset.erase(nums[i]);
//                 sum -= nums[i];
//                 i++;
//             }
//             sum += nums[j];
//             uset.insert(nums[j]);

//             if(j-i+1 == k) {
//                 maxSum = max(maxSum, sum);
                
//                 sum -= nums[i];
//                 uset.erase(nums[i]); 
//                 i++;
//             } 
//             j++;
//         }
//         return maxSum;
//     }
// };











class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, sum = 0;
        unordered_map<int,int> freq;

        int left = 0;
        for(int right = left; right < n; right++){
            sum += nums[right];
            freq[nums[right]]++;

            if(right - left + 1 > k) {
                sum -= nums[left];
                freq[nums[left]]--;
                
                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            if(right - left + 1 == k && freq.size() == k) {
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};