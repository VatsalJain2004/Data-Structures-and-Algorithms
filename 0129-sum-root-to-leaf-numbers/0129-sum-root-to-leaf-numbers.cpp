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
    int sum = 0;
    void numGen(TreeNode* root, int num) {
        num = num*10 + root -> val;
        if(!root -> left && !root -> right) {
            sum += num;
            return;
        }

        if(root -> left) {
            numGen(root -> left, num);
        }
        if(root -> right) { 
            numGen(root -> right, num);
        }
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) {
            return 0;
        }    

        if(!root -> left && !root -> right) {
            return root -> val;
        }

        numGen(root, 0);
        return sum;
    }
};