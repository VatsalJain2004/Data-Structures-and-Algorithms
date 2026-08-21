class Solution {
public:
    int atmost(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum = 0, i = 0, j = 0, cnt = 0;

        while (j < n) {

            sum += nums[j];

            while (i <= j && sum > goal) {
                sum -= nums[i];
                i++;
            }

            cnt += j - i + 1;
            j++;
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};