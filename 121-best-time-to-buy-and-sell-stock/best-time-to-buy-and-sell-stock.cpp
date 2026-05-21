class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0;
        for (int& it: prices) {
            profit = max(it-buy, profit);
            buy = it < buy ? it : buy;
        }

        return profit;
    }
};