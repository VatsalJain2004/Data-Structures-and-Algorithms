class Solution {
public:
    int mirrorDistance(int n) {
        int revn = 0, copyn = n;
        while (copyn) {
            revn = (revn*10) + copyn % 10;
            copyn /= 10;
        }
        cout << n << "   " << revn << endl;

        return abs (n - revn);
    }
};