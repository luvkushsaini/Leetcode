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
    int findLeftHeight(TreeNode*root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }

    int findRightHeight(TreeNode*root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        int h1=findLeftHeight(root);
        int h2=findRightHeight(root);

        if(h1==h2)return (1<<h1)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};