class Solution {
public: // code written by me 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        vector<vector<int>> adj(501);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node->left){
                adj[node->val].push_back(node->left->val);
                adj[node->left->val].push_back(node->val);
                q.push(node->left);
            }
            if(node->right){
                adj[node->val].push_back(node->right->val);
                adj[node->right->val].push_back(node->val);
                q.push(node->right);
            }
        }

        vector<int> vis(501, 0);
        queue<pair<int, int>> q1;
        q1.push({target->val, 0});
        vis[target->val] = 1;

        while(!q1.empty()){
            int data = q1.front().first;
            int dist = q1.front().second;
            q1.pop();

            if(dist == k) ans.push_back(data);

            for(int i=0; i<adj[data].size(); i++){
                if(!vis[adj[data][i]]){
                    q1.push({adj[data][i], dist+1});
                    vis[adj[data][i]] = 1;
                }
            }
        }

        return ans;
    }
};
