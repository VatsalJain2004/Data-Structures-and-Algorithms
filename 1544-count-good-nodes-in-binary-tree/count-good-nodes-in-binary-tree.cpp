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
    int numberOfGoodNodes = 0;

    void goodNodesChecker (TreeNode* root, int maxVal) {
        if (!root) return;
        
        int maximum = max(maxVal, root -> val);
        // if maxVal <= root -> val
        numberOfGoodNodes += maximum == root -> val ? 1 : 0;
        
        if (root -> left) {
            goodNodesChecker (root -> left, maximum);
        }

        if (root -> right) {
            goodNodesChecker (root -> right, maximum);
        } 
    }

    int goodNodes(TreeNode* root) {
        goodNodesChecker(root, root -> val);
        return numberOfGoodNodes;    
    }
};