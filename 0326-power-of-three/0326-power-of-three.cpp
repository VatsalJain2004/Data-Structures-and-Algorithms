class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n) {
            return false;
        }

        int n_copy = n;
        while(n_copy) {
            if(n_copy == 1) {
                return true;
            }
            if(!(n_copy % 3)) {
                n_copy /= 3;
            }
            else {
                return false;
            }
            cout << n_copy << endl;
        }
        return true;
        // return n == 0 ? false : true;
    }
};