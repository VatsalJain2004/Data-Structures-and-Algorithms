class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos = 0, max = 0;
        for (char& c: moves) {
            if (c == 'L') {
                pos -= 1;
            }
            else if (c == 'R') {
                pos += 1;
            }
            else {
                max += 1;
            }
        }

        return abs(pos) + max;
    }
};