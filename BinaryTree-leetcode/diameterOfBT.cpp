class Solution {
public:
    int maxDia = 0;

    //finding the levels/depth of each node here
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;  //base case

        int dia = levels(root->left) + levels(root->right); //we calculate the dia of each node
                                                           //here for now its the root node, so using root we are findind the max dia 
        maxDia = max(dia, maxDia);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxDia;
    }
};
