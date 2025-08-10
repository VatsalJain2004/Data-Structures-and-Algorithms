// class Solution {
// public:
//     string getSortedStr(int n) {
//         string str = to_string(n);
//         sort(str.begin(), str.end());
//         return str;
//     }

//     bool reorderedPowerOf2(int n) {
//         string str = getSortedStr(n);
//         for(int p = 0; p <= 29; p++) {  // 2 ^ x >= 1e9 ? x = 30, i.e at x = 29 2^x > 1e9.
//             if(str == getSortedStr(1 << p)) {
//                 return true;
//             }
//         }    
//         return false;
//     }
// };


// class Solution {
// public:
//     string getSortedStr(int n) {
//         string str = to_string(n);
//         sort(str.begin(), str.end());
//         return str;
//     }

//     bool reorderedPowerOf2(int n) {
//         string str = getSortedStr(n);
//         for(int p = 0; p <= 29; p++) {  // 2 ^ x >= 1e9 ? x = 30, i.e at x = 29 2^x > 1e9.
//             string temp = to_string(1 << p);
//             if(temp.length() == str.length() && str == getSortedStr(1 << p)) {
//                 return true;
//             }
//         }    
//         return false;
//     }
// };











class Solution {
public:
    unordered_set<string> uset;
    void generatePowerOf2InSortedOrder() {
        for(int p = 0; p <= 29; p++) {  // 2 ^ x >= 1e9 ? x = 30, i.e at x = 29 2^x > 1e9.
            string temp = to_string(1 << p);
            sort(temp.begin(),temp.end());
            uset.insert(temp);
        }
        return;
    }

    bool reorderedPowerOf2(int n) {
        if(uset.empty()) {
            generatePowerOf2InSortedOrder();
        }

        string str = to_string(n);
        sort(str.begin(),str.end());
        return uset.count(str);
    }
};