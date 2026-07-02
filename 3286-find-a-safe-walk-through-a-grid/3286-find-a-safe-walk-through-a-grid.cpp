class Solution {
public:
     vector<int>r={-1,1,0,0};
     vector<int>c={0,0,-1,1};
     int n,m;

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n=grid.size();
        m=grid[0].size();

        priority_queue<tuple<int,int,int>>pq;
        pq.push({health-grid[0][0],0,0});

        vector<vector<int>>vis(n,vector<int>(m,0));


        while(!pq.empty()){
            auto [currHealth,i,j]=pq.top();
            pq.pop();
            if(vis[i][j]==1 || currHealth==0)continue;
            if(i==n-1 && j==m-1)return true;
            vis[i][j]=1;

            for(int k=0;k<4;k++){
                int x=i+r[k];
                int y=j+c[k];
                if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0){
                    int updatedHealth=currHealth-grid[x][y];
                    pq.push({updatedHealth,x,y});
                }
            }
        }

        return false;

    }
};