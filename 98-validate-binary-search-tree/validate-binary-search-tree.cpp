class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)   
            return true;
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* root, long long min, long long max){
        if(!root)
            return true;
            
        if(root -> val >= max || root -> val <= min)
            return false;

        return check(root -> left, min, root -> val) && check(root -> right, root -> val, max);
    }
};