class Solution {
public:
    int maximum69Number (int num) {
        int index = -1;
        string numString = to_string(num);
        for(int i = 0; i < numString.length(); i++) {
            if(numString[i] == '6') {
                numString[i] = '9';
                index = i;
                break;
            }
        }
        
        cout << numString << endl;
        int num_copy = 0;
        for(int i = 0; i < numString.length(); i++) {
            num_copy = num_copy*10 + (numString[i]-'0');
        }   
        cout << num_copy << endl;
        return num_copy;
    }
};