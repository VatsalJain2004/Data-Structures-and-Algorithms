class Solution {
public:
    vector<int> coins;
    vector<vector<int>> dp;
    int n;

    int coinChangeTabulation (int& amount) {
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0)
               dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int pick = 1e9;
                if (j >= coins[i]) 
                    pick = 1 + dp[i][j - coins[i]];

                int npick = dp[i-1][j];
                dp[i][j] = min(pick, npick);
            }
        }

        return dp[n-1][amount];
    }

    int coinChangeMemoization (int i, int target) {
        if (i == 0) {
            if (target % coins[i] == 0) return dp[i][target] = (target / coins[i]);
            else return dp[i][target] = 1e9;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int pick = 1e9;
        if (target >= coins[i])
            pick = 1 + coinChangeMemoization (i, target-coins[i]);
        int npick = coinChangeMemoization (i-1, target);

        return dp[i][target] = min(pick, npick);
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        this -> coins = coins;
        n = coins.size();

        // size --> rows, amount --> columns
        dp = vector<vector<int>>(n, vector<int>(amount+1, 0));
        return coinChangeTabulation (amount) == 1e9 ? -1 : dp[n-1][amount];
    }
};