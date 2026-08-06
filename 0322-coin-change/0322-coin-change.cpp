class Solution {
public:
    vector<int> coins;
    vector<vector<int>> dp;
    int n;

    int coinChangeRecursion (int i, int target) {
        if (i == 0) {
            if (target % coins[i] == 0) return dp[i][target] = (target / coins[i]);
            else return dp[i][target] = 1e9;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int pick = 1e9;
        if (target >= coins[i])
            pick = 1 + coinChangeRecursion (i, target-coins[i]);
        int npick = coinChangeRecursion (i-1, target);

        return dp[i][target] = min(pick, npick);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        this -> coins = coins;
        n = coins.size();
        dp = vector<vector<int>>(n, vector<int>(amount+1, -1));
        int coinsNeeded = coinChangeRecursion (n-1, amount);

        return (coinsNeeded == 1e9 || coinsNeeded == 0) ? -1 : coinsNeeded;
    }
};