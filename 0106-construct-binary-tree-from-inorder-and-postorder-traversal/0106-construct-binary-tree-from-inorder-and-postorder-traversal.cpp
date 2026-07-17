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
    TreeNode*solve(int i,int j,int k ,int l,vector<int>& inorder, vector<int>& postorder){
        if(i>j || k>l)return nullptr;
        TreeNode*root=new TreeNode(postorder[l]);
        int val=postorder[l];
        int p=i;
        while(p<=j){
            if(inorder[p]==val)break;
            p++;
        }
        int nodeCount=j-p;
        int new_l=l-(nodeCount+1);
        root->left=solve(i,p-1,k,new_l,inorder,postorder);
        root->right=solve(p+1,j,new_l+1,l-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder);
    }
};