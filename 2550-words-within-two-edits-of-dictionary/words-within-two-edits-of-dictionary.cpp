class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        int n = queries[0].length();

        for (auto &q : queries) {
            for (auto &d : dictionary) {
                int diff = 0;

                for (int i = 0; i < n; i++) {
                    if (q[i] != d[i]) {
                        diff++;
                        if (diff > 2) break;
                    }
                }

                if (diff <= 2) {
                    result.push_back(q);
                    break;
                }
            }
        }

        return result;
    }
};