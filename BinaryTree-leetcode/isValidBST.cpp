//understand this that if we take inorder of any BT and if its strictly in increasing order then its a valid BST

class Solution {
public:
    void helper(TreeNode* root, vector<int>& v){
        if(root == NULL) return;

        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        helper(root, v);
        for(int i=1;i<v.size();i++){
            if(v[i] <= v[i-1]) return false;  //checking vals if they are strictly increasing
        }
        return true;
    }
};
