class Solution {
public:
    int n;
    vector<vector<int>>vis;
    vector<vector<int>>dist;

    vector<int>r={-1,1,0,0};
    vector<int>c={0,0,-1,1};

    bool fun(int mid,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;

            if(dist[x][y]<mid)continue;

            if(x==n-1 && y==n-1){
                return true;
            }

            for(int k=0;k<4;k++){
                int new_r=x+r[k];
                int new_c=y+c[k];

                if(new_r>=0 && new_r<n && new_c>=0 && new_c<n && vis[new_r][new_c]==0){
                    vis[new_r][new_c]=1;
                    q.push({new_r,new_c});
                }
            }
        }

        return false;
    }

    void bfs(vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        int level=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;

            for(int k=0;k<4;k++){
                int new_r=x+r[k];
                int new_c=y+c[k];

                if(new_r>=0 && new_r<n && new_c>=0 && new_c<n && vis[new_r][new_c]==0){
                    vis[new_r][new_c]=1;
                    dist[new_r][new_c]=1+dist[x][y];
                    q.push({new_r,new_c});
                }
            }
        }
    }


    int maximumSafenessFactor(vector<vector<int>>& grid) {
         n=grid.size();

        vis.assign(n,vector<int>(n,0));
        dist.assign(n,vector<int>(n,0));
        bfs(grid);


        int low=0;
        int high=2*(n-1);
        int ans;

        while(low<=high){
            int mid=low+(high-low)/2;
            vis.assign(n,vector<int>(n,0));

            if(fun(mid,grid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;
    }
};