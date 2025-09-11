// class Solution {
// public:
//     int maxBalancedShipments(vector<int>& weight) {
//         int n = weight.size();
//         int maxShipments = 0, maxi = 0, lastParcel = 0;
//         for(int j = 0; j < n; j++) {
//             maxi = max(maxi, weight[j]);
//             lastParcel = weight[j];

//             if(maxi > lastParcel) {
//                 maxShipments += 1;
//                 maxi = lastParcel = 0;
//             }
//         }
        
//         return maxShipments;
//     }
// };


class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int maxShipments = 0;
        for(int j = 1; j < n; j++) {
            if(weight[j] < weight[j-1]) {
                maxShipments += 1;
                j++;
            }
        }
        
        return maxShipments;
    }
};