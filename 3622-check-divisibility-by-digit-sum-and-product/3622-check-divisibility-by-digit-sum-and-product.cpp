class Solution {
public:
    bool checkDivisibility(int n) {
        int copyN = n;
        int sum = 0, product = 1;
        while (n) {
            sum += n % 10;
            product *= (n % 10);
            n = n / 10;
        }
        n = copyN;
        return !(copyN % (sum + product));
    }
};