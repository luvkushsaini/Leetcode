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
    int balanced(TreeNode*root){
        if(root==NULL)return 0;

        if(balanced(root->left)==-1 || balanced(root->right)==-1)return -1;
        if(abs(balanced(root->left)-balanced(root->right))>1)return -1;

        return 1+max(balanced(root->left),balanced(root->right));
    }
    bool isBalanced(TreeNode* root) {
        return (balanced(root)==-1)?false:true;
    }
};