class Solution {
public:
    static int maxNumberOfBalloons(string& text) {
        int freq[5]={0};
        for(char& c : text){
            if (c == 'b') {
                freq[0] += 1;
            }
            else if (c == 'a') {
                freq[1] += 1;
            }
            else if (c == 'l') {
                freq[2] += 1;
            }
            else if (c == 'o') {
                freq[3] += 1;
            }
            else if (c == 'n') {
                freq[4] += 1;
            }
       }
        return min({freq[0], freq[1], freq[2]>>1, freq[3]>>1, freq[4]});
    }
};