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


// ********************* //
//method 2:
class Solution {
public:
    bool ans;

    int levels(TreeNode* root){
        if(root == NULL) return 0;

        int left = levels(root->left);
        int right = levels(root->right);

        if(abs(left - right) > 1) ans = false; //check the condn here so that unnecessary calculations are not done

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        ans = true; // means balanced tree
        levels(root);
        return ans;
    }
};

