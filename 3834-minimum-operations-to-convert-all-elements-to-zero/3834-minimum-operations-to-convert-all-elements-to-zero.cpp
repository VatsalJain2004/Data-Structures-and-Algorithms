// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         stack<int> st;
//         st.push(-1);
//         int totalOperations = 0;
//         int i = 0, n = nums.size();
//         while(i < n) {
//             while(st.top() > nums[i]) {   
//                 st.pop();
//             }
            
//             if(nums[i]!=0 && st.top() < nums[i]) {
//                 totalOperations += 1; 
//             }
            
//             st.push(nums[i]);
//             i++;
//         }
//         return totalOperations;
//     }
// };








class Solution {
public:
    int minOperations(vector<int>& nums) {
        nums.push_back(0);
        vector<int> stack; 
        int numberOfOperations = 0;
        int n = nums.size(); 
        for(int i = 0; i < n; i++){
            while(!stack.empty()){
                if(nums[i] > stack.back()){
                    stack.push_back(nums[i]);
                    break; 
                }
                else if(nums[i] < stack.back()){
                    stack.pop_back();
                    numberOfOperations++; 
                }
                else{
                    break; 
                }
            }
            if(stack.empty() && nums[i]){
                stack.push_back(nums[i]);
            }
        }
        return numberOfOperations;       
    }
};