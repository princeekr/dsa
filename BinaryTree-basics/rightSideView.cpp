class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void rightside(TreeNode* root, vector<int>& ans, int level){
        if(root == NULL) return;
        ans[level] = root->val;  //vals will keep updating till they reach the right most node and thats what we want. 
        rightside(root->left, ans, level+1);
        rightside(root->right, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root), 0);
        rightside(root, ans, 0);
        return ans;
    }
};
