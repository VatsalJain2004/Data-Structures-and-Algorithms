class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        string ans = "";
        int n = s.length();
        for(int i = 0; i < numRows; i++) {
            int ind = i;
            int deltaDown = 2*(numRows-1-i), deltaUp = 2*(i);
            bool dirDown = true;
            while(ind < n) {
                ans += s[ind];
                if(i == 0) {
                    ind += deltaDown;
                }
                else if(i == numRows-1) {
                    ind += deltaUp;
                }
                else {
                    if(dirDown) {
                        ind += deltaDown;
                    }
                    else if(!dirDown) {
                        ind += deltaUp;
                    }
                }
                dirDown = !dirDown;
            }
        }
        return ans;
    }
};