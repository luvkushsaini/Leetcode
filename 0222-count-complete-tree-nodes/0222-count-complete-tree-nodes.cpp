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
public://must do 
    int findLeftHeight(TreeNode*root){
        if(root==NULL)return 0;
        int height=0;
        while(root){
            height+=1;
            root=root->left;
        }
        return height;
    }

    int findRightHeight(TreeNode*root){
        if(root==NULL)return 0;
        int height=0;
        while(root){
            height+=1;
            root=root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int leftHeight=findLeftHeight(root);
        int rightHeight=findRightHeight(root);
        if(leftHeight==rightHeight){
            return (1<<leftHeight)-1;
        }
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};