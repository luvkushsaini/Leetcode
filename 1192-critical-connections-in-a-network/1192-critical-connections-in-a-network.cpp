class Solution {
public:
    //Tarjan's Algo
    vector<vector<int>>adj;
    vector<vector<int>>bridges;
    vector<int>vis;
    vector<int>insertTime,lowestTime;
    int timer=1;
    void dfs(int i,int par){
        vis[i]=1;
        insertTime[i]=timer;
        lowestTime[i]=timer;
        timer++;
        for(int child:adj[i]){
            if(child==par)continue;
            if(!vis[child]){
                dfs(child,i);
                lowestTime[i]=min(lowestTime[i],lowestTime[child]);
                if(insertTime[i]<lowestTime[child])bridges.push_back({i,child});
            }
            else{
                lowestTime[i]=min(lowestTime[i],lowestTime[child]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        vis.assign(n,0);
        insertTime.resize(n);
        lowestTime.resize(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,0);
        return bridges;

    }
};