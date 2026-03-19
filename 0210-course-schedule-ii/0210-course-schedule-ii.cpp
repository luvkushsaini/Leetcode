class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);

        for(int i=0;i<prerequisites.size();i++){
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];

            indegree[x]++;
            adj[y].push_back(x);
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto x:adj[node]){
                int new_node=x;
                indegree[new_node]--;
                if(indegree[new_node]==0){
                    q.push(new_node);
                }
            }

        }

       if(ans.size()==n)return ans;
       return {};
    }
};