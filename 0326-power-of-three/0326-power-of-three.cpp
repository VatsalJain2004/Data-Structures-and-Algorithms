class Solution {
public:
    bool isPowerOfThree(int n) {
            long long ans = n;

        if(ans == 0)
            return false;
        
        if(ans == 1)
            return true;
        
        if(ans % 3 == 0){
            ans = ans / 3;
            return isPowerOfThree(ans);
        }
        return false;
    }
};