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
    TreeNode*solve(int i,int j,int k,int l,vector<int>& inorder, vector<int>& preorder){
        if(i>j || k>l)return nullptr;
        int val=preorder[k];
        TreeNode*root=new TreeNode(val);

        int p=i;
        while(p<=j){
            if(inorder[p]==val)break;
            p++;
        }

        int nodeCount=p-i;
        int new_k=k+nodeCount+1;
        root->right=solve(p+1,j,new_k,l,inorder,preorder);
        root->left=solve(i,p-1,k+1,new_k-1,inorder,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0,inorder.size()-1,0,preorder.size()-1,inorder,preorder);
    }
};