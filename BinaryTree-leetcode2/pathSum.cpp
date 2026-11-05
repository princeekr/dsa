class Solution {
public:
    //start with target sum and keep subtracting the targetsum using root vals and go down. 

    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;  //null tree, means pathsum is not possible. 

        if(root->left == NULL && root->right == NULL) return (sum == root->val); //check if sum equals leaf node val

        return hasPathSum(root->left, sum - (root->val)) || hasPathSum(root->right, sum - (root->val));  //either go left/right
    }
};