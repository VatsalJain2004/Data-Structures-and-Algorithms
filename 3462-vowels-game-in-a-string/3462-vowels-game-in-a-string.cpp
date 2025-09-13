// class Solution {
// private:
//     bool isVowel(char ch){
//         return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u');
//     }
    
// public:
//     bool doesAliceWin(string s) {
//         int vowels = 0;
//         for(auto ch : s) {
//             if(isVowel(ch)) {
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };


class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u');
    }
    
public:
    bool doesAliceWin(string s) {
        int vowels = 0;
        for(auto ch : s) {
            if(isVowel(ch)) {
                vowels += 1;
            }
        }
        
        return vowels ? true : false;
    }
};