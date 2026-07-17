class Solution {
public:
    struct DSU{
        vector<int>size;
        vector<int>par;

        DSU(int n){
            size.resize(n,1);
            par.resize(n);
            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }

        int findPar(int u){
            if(par[u]==u)return u;
             return par[u]=findPar(par[u]);
        }

        void unionBySize(int u,int v){
            int p1=findPar(u);
            int p2=findPar(v);

            if(p1==p2)return ;
            int size1=size[p1];
            int size2=size[p2];

            if(size1<size2)swap(p1,p2);
            size[p1]+=size[p2];
            par[p2]=p1;
        }
    };

    vector<vector<int>>vis;
    vector<int>r={-1,1,0,0};
    vector<int>c={0,0,-1,1};
    int n;
    void dfs(int i,int j,vector<vector<int>>&grid,DSU &dsu){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int x=i+r[k];
            int y=j+c[k];
            if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==0 && grid[x][y]==1){
                dsu.unionBySize(i*n+j,x*n+y);
                dfs(x,y,grid,dsu);
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        DSU dsu(n*n);

        vis.assign(n,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] || grid[i][j]==0)continue;
                dfs(i,j,grid,dsu);
                ans=max(ans,dsu.size[dsu.findPar(i*n+j)]);
            }
        }

        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                st.clear();
                for(int k=0;k<4;k++){
                    int x=i+r[k];
                    int y=j+c[k];
                    if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==1){
                        int parent=dsu.findPar(x*n+y);
                        st.insert(parent);
                    }
                }

                int sum=1;
                for(int num:st){
                    sum+=dsu.size[num];
                }
                ans=max(ans,sum);
            }
        }

        return ans;
    }
};