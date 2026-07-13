class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long curResource = k, costIncur = 1, totalCost = 0;
        for (int& it: nums) {
            if (curResource < it) {
                long long need = it - curResource;
                long long operations = ((need + k - 1) / k);

                long long cost = ((operations) * ((2 * costIncur + operations - 1) % MOD) / 2) % MOD;
                totalCost = (totalCost + cost) % MOD;
                costIncur += operations;
                curResource += operations * k * 1LL;
            }

            curResource -= it;
        }

        return totalCost % MOD;
    }
};