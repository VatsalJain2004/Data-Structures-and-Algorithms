class Solution {
public:
    int kthSmallestValue = -1;

    void kthSmallestDFS (TreeNode* root, int& k) {
        if (!root) return;
        if (kthSmallestValue != -1) return;

        kthSmallestDFS (root -> left, k);
        k--;
        if (k == 0) {
            kthSmallestValue = root -> val;
            return;
        }
        kthSmallestDFS (root -> right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        kthSmallestDFS (root, k);
        return kthSmallestValue;
    }
};