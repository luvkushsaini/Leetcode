class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>>q;
        int ans=INT_MAX;
        vector<int>vis(n,0);
        vector<int>dist(n,0);

        for(int i=0;i<n;i++){
            dist.assign(n,0);
            vis.assign(n,0);
            q.push({i,-1});
            int level=-1;
            bool found=false;
            while(!q.empty()){
                level++;
                int size=q.size();
                for(int j=0;j<size;j++){
                auto [node,par]=q.front();
                q.pop();
                if(vis[node])continue;
                dist[node]=level;
                vis[node]=1;

                for(int child:adj[node]){
                    if(child==par)continue;
                    if(vis[child]){
                        ans=min(ans,dist[node]+dist[child]+1);
                        found=true;
                        break;
                    }
                    else{
                        q.push({child,node});
                    }
                }

                if(found)break;
                }
                if(found)break;
            }
            while(!q.empty())q.pop();
        }


        return (ans==INT_MAX?-1:ans);
    }
};