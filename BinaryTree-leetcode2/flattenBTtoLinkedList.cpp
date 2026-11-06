//push each nodes in preorder to vector, then take each ele from vector and connect right of it to next ele and left to null. 

class Solution {
public:
    void dfs(TreeNode* root, vector<TreeNode*>& ans){
        if(root == NULL) return;
        ans.push_back(root);  //store all the tree nodes in preorder
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        dfs(root, ans);

        //connect node right to next ele in arr and left to null
        for(int i=0;i<ans.size();i++){
            if(i < ans.size()-1) ans[i]->right = ans[i+1];
            ans[i]->left = NULL;
        }
    }
};