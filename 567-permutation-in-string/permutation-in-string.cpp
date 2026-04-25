class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) {
            return false;
        }

        vector<int> freq1(26, 0), freq2(26, 0);
        for(char c: s1) {
            freq1[c-'a'] += 1;
        }

        int l = 0;
        for(int r = 0; r < n2;) {
            freq2[s2[r]-'a'] += 1;
            if(r-l+1 == n1) {
                if(freq1 == freq2) {
                    return true;
                }
            }

            if(r-l+1 < n1) {
                r += 1;
            }
            else {
                freq2[s2[l]-'a'] -= 1;
                r += 1;
                l += 1;
            }
        }
        return false;
    }
};