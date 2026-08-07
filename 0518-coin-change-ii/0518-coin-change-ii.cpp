class Solution {
public:
    int n, amount;
    vector<int> coins;
    vector<vector<int>> dp;

    int changeRecursion (int i, int amount) {
        if (i < 0) return 0;
        if (amount == 0) return 1;

        if (amount < coins[i]) 
            return changeRecursion (i-1, amount);

        return changeRecursion (i, amount - coins[i]) + changeRecursion (i-1, amount); 
    }

    int changeMemoization (int i, int amount) {
        if (i < 0) return 0;
        if (amount == 0) return dp[i][amount] = 1;

        if (dp[i][amount] != -1) return dp[i][amount];

        if (amount < coins[i]) 
            return dp[i][amount] = changeMemoization (i-1, amount);

        return dp[i][amount] = changeMemoization (i, amount - coins[i]) + changeMemoization (i-1, amount); 
    }

    int dpInitialization () {
        dp = vector<vector<int>>(n+1, vector<int>(amount+1, -1));
        return changeMemoization (n-1, amount);
    }

    int change(int amount, vector<int>& coins) {
        this -> coins = coins;
        n = coins.size();
        this -> amount = amount;
        
        return dpInitialization ();    
    }
};  