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
    vector<vector<int>> path;
    vector<int> localPath;
    int target;

    void dfs (TreeNode* root, int sum, vector<int> tempPath) {
        if (!root) return;

        sum += root -> val;
        tempPath.push_back(root -> val);

        if (!root -> left && !root -> right && sum == target) {
            path.push_back(tempPath);
            return;
        } 

        dfs (root -> left, sum, tempPath);
        dfs (root -> right, sum, tempPath);

        return;
    }

    void dfsAndBacktrack (TreeNode* root, int sum) {
        if (!root) return;

        sum -= root -> val;
        localPath.push_back(root -> val);

        if (!root -> left && !root -> right && sum == 0) {
            path.push_back(localPath);
            localPath.pop_back();
            return;
        } 

        dfsAndBacktrack (root -> left, sum);
        dfsAndBacktrack (root -> right, sum);

        localPath.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        path.clear();
        localPath.clear();
        this -> target = targetSum;
        if (!root) return path;

        dfsAndBacktrack (root, targetSum);

        return path;
    }
};