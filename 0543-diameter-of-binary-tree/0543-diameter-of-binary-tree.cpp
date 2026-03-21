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
    int mxDiameter;

    int fun(TreeNode*root){
        if(root==NULL)return 0;
        int leftHeight=fun(root->left);
        int rightHeight=fun(root->right);

        mxDiameter=max(mxDiameter,1+leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        mxDiameter=0;
        fun(root);
        return mxDiameter-1;

    }
};