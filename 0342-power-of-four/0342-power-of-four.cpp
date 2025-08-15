class Solution {
public:
    bool isPowerOfFour(int n) {
        // n must be > 0
        // n must be a power of 2 => (n & (n - 1)) == 0
        // n must have the only set bit at an even position => (n & 0x55555555) != 0
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }
};
