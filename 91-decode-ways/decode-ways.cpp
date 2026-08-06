class Solution {
public:
    int n;
    string s;
    int numOfWays = 0;
    vector<int> dp;

    int numDecodingsRecursive(int i) {
        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;

        int pick1 = numDecodingsRecursive(i + 1);

        int pick2 = 0;
        if ((i + 1 < n) && 
                ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6'))
            )
            pick2 = numDecodingsRecursive(i + 2);

        return pick1 + pick2;
    }

    int numDecodingsMemoization(int i) {
        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;
        
        if (dp[i] != -1) return dp[i];

        int pick1 = numDecodingsMemoization(i + 1);

        int pick2 = 0;
        if ((i + 1 < n) && 
                ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6'))
            )
            pick2 = numDecodingsMemoization(i + 2);

        return dp[i] = pick1 + pick2;
    }

    int numDecodingsTabulation() {
        dp[n] = 1;

        for (int i = n-1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            }
            else {
                int pick1 = dp[i+1];
                int pick2 = 0;
                if ((i + 1 < n) && 
                        ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6'))
                    )
                    pick2 = dp[i+2];

                dp[i] = pick1 + pick2;
            }
        }

        return dp[0];
    }

    int numDecodings(string s) {
        n = s.length();
        this->s = s;
        dp = vector<int>(n+1, -1);

        return numDecodingsMemoization(0);
    }
};