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











// class Solution {
// public:
//     unordered_set<string> uset;
//     void generatePowerOf2InSortedOrder() {
//         for(int p = 0; p <= 29; p++) {  // 2 ^ x >= 1e9 ? x = 30, i.e at x = 29 2^x > 1e9.
//             string temp = to_string(1 << p);
//             sort(temp.begin(),temp.end());
//             uset.insert(temp);
//         }
//         return;
//     }

//     bool reorderedPowerOf2(int n) {
//         if(uset.empty()) {
//             generatePowerOf2InSortedOrder();
//         }

//         string str = to_string(n);
//         sort(str.begin(),str.end());
//         return uset.count(str);
//     }
// };








// class Solution {
// public:
//     vector<int> getVectorCountFormat(int n) {
//         vector<int> vec(10, 0);
//         while(n) {
//             vec[n%10]++;
//             n = n / 10;
//         }
//         return vec;
//     }

//     bool reorderedPowerOf2(int n) {
//         vector<int> vec = getVectorCountFormat(n);
//         for(int i = 0; i < 30; i++) {
//             if(vec == getVectorCountFormat(1 << i)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };









class Solution {
public:
    int getIntergerCountFormat(int n) {
        int num = 0;
        while(n) {
            num += pow(10, n%10);
            n = n / 10;
        }
        return num;
    }

    bool reorderedPowerOf2(int n) {
        int input = getIntergerCountFormat(n);
        for(int i = 0; i < 30; i++) {
            if(input == getIntergerCountFormat(1 << i)) {
                return true;
            }
        }
        return false;
    }
};