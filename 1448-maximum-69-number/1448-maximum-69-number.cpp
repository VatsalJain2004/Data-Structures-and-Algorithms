// class Solution {
// public:
//     int maximum69Number (int num) {
//         int index = -1;
//         string numString = to_string(num);
//         for(int i = 0; i < numString.length(); i++) {
//             if(numString[i] == '6') {
//                 numString[i] = '9';
//                 index = i;
//                 break;
//             }
//         }
        
//         cout << numString << endl;
//         int num_copy = 0;
//         for(int i = 0; i < numString.length(); i++) {
//             num_copy = num_copy*10 + (numString[i]-'0');
//         }   
//         cout << num_copy << endl;
//         return num_copy;
//     }
// };








// class Solution {
// public:
//     int maximum69Number (int num) {
//         std::string s = std::to_string(num);
//         for (char &c : s) {
//             if (c == '6') { 
//                 c = '9'; 
//                 break; 
//             }
//         }
//         return std::stoi(s);
//     }
// };







class Solution {
public:
    int maximum69Number (int num) {
        int indexOf6 = -1, index = 0, num_copy = num;
        while(num_copy) {
            if(num_copy%10 == 6) {
                indexOf6 = index;
            }
            num_copy /= 10;
            index++;
        }
        return indexOf6 == -1 ? num : num + (3*pow(10, indexOf6));
    }
};