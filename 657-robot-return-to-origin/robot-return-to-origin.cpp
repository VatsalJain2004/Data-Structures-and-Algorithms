class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, r = 0;
        for(char c: moves) {
            if (c == 'D') {
                u -= 1;
            }
            else if (c == 'U') {
                u += 1;
            }
            else if (c == 'R') {
                r += 1;
            }
            else {
                r -= 1;
            }
        }
        return u == 0 && r == 0;
    }
};