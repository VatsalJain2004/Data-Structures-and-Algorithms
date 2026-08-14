class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if (!root) return -1;

        int left = kthSmallest(root->left, k);

        if (k == 0) return left;

        k--;

        if (k == 0) return root->val;

        return kthSmallest(root->right, k);
    }
};