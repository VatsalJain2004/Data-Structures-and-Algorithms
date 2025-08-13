// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//             long long ans = n;

//         if(ans == 0)
//             return false;
        
//         if(ans == 1)
//             return true;
        
//         if(ans % 3 == 0){
//             ans = ans / 3;
//             return isPowerOfThree(ans);
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool isPowerOfThree(int n) {
        int n_copy = n;
        while(n_copy % 3 == 0 && n_copy != 0) {
            n_copy /= 3;
        }
        return n_copy == 1;
    }
};










// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         // If n is less than or equal to 0, it's not a power of three
//         if (n <= 0) return false;
        
//         // 1162261467 is the largest power of 3 that fits within a 32-bit integer
//         return 1162261467 % n == 0;
//     }
// };