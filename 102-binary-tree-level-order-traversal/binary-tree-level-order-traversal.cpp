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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        } 

        vector<vector<int>> levelOrder;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> levelTraversal;
            for(int i = 0; i < size; i++) {
                TreeNode *temp = q.front();
                levelTraversal.push_back(temp -> val);
                q.pop();

                if(temp -> left) {
                    q.push(temp -> left);
                }

                if(temp -> right) {
                    q.push(temp -> right);
                }
            }

            levelOrder.push_back(levelTraversal);
        }
        return levelOrder;
    }
};