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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>results;
        TreeNode*curr=root;

        while(curr!=NULL){
            results.push_back(curr->val);
            TreeNode*rightChild=curr->right;
            if(curr->left==NULL){
                curr=rightChild;
            }
            else{
                TreeNode*leftChild=curr->left;
                TreeNode*temp=leftChild;
                while(temp->right!=NULL){
                    temp=temp->right;
                }
                temp->right=rightChild;
                curr->left=NULL;
                curr=leftChild;
            }
        }

        return results;
    }
};