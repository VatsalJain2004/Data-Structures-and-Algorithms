class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If there are no remainder-1 or remainder-2 stones,
        // nobody can make the sum non-zero again.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // If cnt[0] is even, Alice wins iff both types 1 and 2 exist
        // with a sufficient imbalance.
        if (cnt[0] % 2 == 0) {
            return cnt[1] >= 1 && cnt[2] >= 1;
        }

        // If cnt[0] is odd, one of the two types must have
        // enough stones to force the opponent into losing.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};