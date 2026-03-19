class Solution {
public:
vector<int>visited;
vector<int>color;

bool dfs(int i,vector<vector<int>>& graph){
    visited[i]=1;
    bool final=true;
    for(auto x:graph[i]){
        if(visited[x]==1 && color[x]==color[i])final&=false;
        else if(visited[x]==0){
            color[x]=1^color[i];
            final&=dfs(x,graph);
        }
    }
    return final;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        int col=0;
        visited.resize(n,0);
        color.resize(n,-1);
        bool ans=true;
        for(int i=0;i<=n-1;i++){
            if(visited[i]==0){
                ans&=dfs(i,graph);
            }
        }
        return ans;
    }
};