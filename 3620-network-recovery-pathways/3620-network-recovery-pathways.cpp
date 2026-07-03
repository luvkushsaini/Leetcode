class Solution {
public:
    int n;
    vector<vector<pair<int,int>>>adj;
    vector<int>vis;

    bool Dijkstra(int mid,vector<bool>& online, long long k){
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vis.assign(n,0);

        while(!pq.empty()){
            auto [cost,v]=pq.top();
            pq.pop();
            if(vis[v])continue;
            vis[v]=1;
            if(v==n-1)return true;

            for(auto [neighbour,currCost]:adj[v]){
                if(vis[neighbour] || !online[neighbour] || currCost<mid)continue;
                long long newCost=cost+currCost;
                if(newCost>k)continue;
                pq.push({newCost,neighbour});
            }
        }

        return false;
    }


    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
         n=online.size();
        adj.resize(n);
        vis.assign(n,0);
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto& edge:edges){
            int u=edge[0];
            int v=edge[1];
            int cost=edge[2];
            adj[u].push_back({v,cost});

            low=min(low,cost);
            high=max(high,cost);
        }

        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(Dijkstra(mid,online,k)){
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }

        return ans;
    }
};