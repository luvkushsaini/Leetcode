class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(auto &p:prerequisites){
            int x=p[0];
            int y=p[1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty()){
            int c=q.front();
            q.pop();
            ans.push_back(c);

            for(int i=0;i<adj[c].size();i++){
                indegree[adj[c][i]]--;
                if(indegree[adj[c][i]]==0){
                    q.push(adj[c][i]);
                }
            }

        }
        if(ans.size()!=n)return {};
        else return ans;
    }
};