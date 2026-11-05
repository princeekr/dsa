class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //basic conditions for same tree
        if(p == NULL & q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;

        //since we need to check the symmetric then check left of p and right of q and vice versa. 
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSameTree(root->left, root->right);
    }
};