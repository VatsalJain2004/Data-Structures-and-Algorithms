// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         sort(potions.begin(), potions.end());

//         int n = spells.size(), m = potions.size();

//         vector<int> pairs(n, 0);
//         for(int i = 0; i < n; i++){
//             int low = 0, high = m-1;
//             while(low <= high){
//                 int mid = low + (high-low)/2;
//                 long long product = (long long)potions[mid] * (long long)spells[i];

//                 if(product >= success)
//                     high = mid - 1;
//                 else 
//                     low = mid + 1;
//             }
//             pairs[i] =  m - low;
//         }
//         return pairs;
//     }
// };









// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int postfix[100001] = {0};
        
//         for(auto potion: potions) 
//             postfix[potion]++;
        
//         for(int i = 99999; i >= 0; i--)     
//             postfix[i] += postfix[i+1];

//         for(int i = 0; i < spells.size(); i++){
//             long long val = success / (long long) spells[i];
//             if(success % (long long) spells[i] != 0) val++;

//             spells[i] = val <= 1e5 ? postfix[val] : 0;
//         }
//         return spells;
//     }
// };











class Solution {
public:
    int BS(vector<int>& potions, int spell, long long success) {
        int m = potions.size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long product = (long long)potions[mid] * (long long)spell;

            if(product >= success)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return m - low; 
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        int n = spells.size();
        vector<int> pairs(n, 0);

        for(int i = 0; i < n; i++)
            pairs[i] = BS(potions, spells[i], success);

        return pairs;
    }
};
