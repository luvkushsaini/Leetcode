class Solution {
public:
   //BinaryLifting Best Question 
   //See codeStroyWithMik to understand the concept
    const int M=1000000007;
    vector<int>depth;
    int n;
    unordered_map<int,vector<int>>adj;
    vector<vector<int>>ancestors;
    int row,col;
    void dfs(int i,int par,int currDepth){
        depth[i]=currDepth;

        for(int child:adj[i]){
            if(child==par)continue;
            ancestors[child][0]=i;
            dfs(child,i,currDepth+1);
        }
        return;
    }

    void fillTable(){
        for(int j=1;j<col;j++){
            for(int node=0;node<row;node++){
                if(ancestors[node][j-1]!=-1){
                    ancestors[node][j]=ancestors[ancestors[node][j-1]][j-1];
                }
            }
        }
    }

    int findLCA(int u,int v){
        if(depth[u]<depth[v])swap(u,v);
        int k=depth[u]-depth[v];
        for(int j=0;j<col;j++){
            if(1&(k>>j)){
                u=ancestors[u][j];
            }
            if(u==-1)break;
        }
        if(u==v)return u;
        for(int j=col-1;j>=0;j--){
            if(ancestors[u][j]!=ancestors[v][j]){
                u=ancestors[u][j];
                v=ancestors[v][j];
            }
        }

        return ancestors[u][0];
    }

    int exponent(int base,int exp){
        if(exp==0)return 1;
        
        int half=exponent(base,exp/2);
        int result=(1LL*half*half)%M;
        if(exp%2)result=(result*base)%M;
        return result;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(auto& edge:edges){
            int u=edge[0]-1;
            int v=edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        n=edges.size()+1;
        depth.resize(n);
        row=n;
        col=log2(n)+1;
        ancestors.resize(row,vector<int>(col,-1));
        dfs(0,-1,0);
        fillTable();

        vector<int>ans;

        for(int i=0;i<queries.size();i++){
            int u=queries[i][0]-1;
            int v=queries[i][1]-1;

            int lca=findLCA(u,v);

            int pathLength=depth[u]+depth[v]-2*depth[lca];
            if(pathLength==0){
                ans.push_back(0);
                continue;
            }
            int result=exponent(2,pathLength-1);
            ans.push_back(result);
        }

        return ans;

    }
};