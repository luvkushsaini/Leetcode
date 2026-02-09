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
    vector<int>v;

    void inorder(TreeNode*root){
        if(root->left!=nullptr){
            inorder(root->left);
        }
        v.push_back(root->val);

        if(root->right!=nullptr){
            inorder(root->right);
        }
    }

    TreeNode*solve(int l,int r){
        int mid=l+(r-l)/2;
        TreeNode *newNode=new TreeNode(v[mid]);
        if(mid!=l && mid>0)newNode->left=solve(l,mid-1);
        if(mid!=r)newNode->right=solve(mid+1,r);

        return newNode;
    }

     
    TreeNode* balanceBST(TreeNode* root) {

        inorder(root);
        int size=v.size();
        return solve(0,size-1);
    }
};