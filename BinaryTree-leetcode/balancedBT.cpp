class Solution {
public:
    int dif = 0;

    //finding depth/levels of tree
    int levels(TreeNode* root){
        if(root == NULL) return NULL;
        return 1 + max(levels(root->left), levels(root->right));
    }

    bool isBalanced(TreeNode* root) {
       if(root == NULL) return true; //NULL tree - balanced

       dif = abs(levels(root->left) - levels(root->right));
       if(dif > 1) return false; //as per Q

       return isBalanced(root->left) && isBalanced(root->right);
    }
};
