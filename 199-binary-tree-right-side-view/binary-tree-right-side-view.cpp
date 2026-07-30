/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void rightNodes(TreeNode *root, int level, vector<int>& ans){
        if(!root)  return;
        
        if(level == ans.size())  ans.push_back(root -> val);

        rightNodes(root -> right, level + 1, ans);
        rightNodes(root -> left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root)  return {};
        vector<int> ans;
        rightNodes(root, 0, ans);
        return ans;
    }
};











// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root)  return {};

//         map<int, int> mpp;
//         queue<pair<TreeNode*, int>> q;
//         q.push({root, 0});

//         while(!q.empty()){
//             TreeNode* node = q.front().first;
//             int level = q.front().second;
//             q.pop();

//             if(mpp.find(level) == mpp.end()) {
//                 mpp[level] = node -> val;
//             }
            
//             if(node -> right){
//                 q.push({node -> right, level+1});
//             }
//             if(node -> left) {
//                 q.push({node -> left, level+1});
//             }
//         }

//         vector<int> ans;
//         for(auto it: mpp)  ans.push_back(it.second);

//         return ans;
//     }
// };
