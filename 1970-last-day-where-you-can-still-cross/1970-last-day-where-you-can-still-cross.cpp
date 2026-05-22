class Solution {
public:

    int n,m;
    vector<int>rows={-1,1,0,0};
    vector<int>cols={0,0,-1,1};


    bool dfs(int i,int j, vector<vector<int>>& matrix, vector<vector<int>>&pathVisited){
        if(matrix[i][j]==0 || pathVisited[i][j]==1)return false;
        if(i==n-1)return true;
        pathVisited[i][j]=1;

        bool x=false;

        for(int k=0;k<4;k++){
            int new_r=rows[k]+i;
            int new_c=cols[k]+j;

            if(new_r>=0 && new_r<n && new_c>=0 && new_c<m){
                x|=dfs(new_r,new_c,matrix,pathVisited);
            }
        }
        return x;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n=row;
        m=col;
        vector<vector<int>>matrix(n,vector<int>(m,1));
        vector<vector<int>>pathVisited;


        int low=0;
        int high=cells.size()-1;
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            pathVisited.assign(n,vector<int>(m,0));

            for(int i=0;i<=mid;i++){
                int r=cells[i][0]-1;
                int c=cells[i][1]-1;
                matrix[r][c]=0;
            }

            bool flag=false;
            for(int j=0;j<m;j++){
                 flag|=dfs(0,j,matrix,pathVisited);
            }


            if(flag){
                    ans=mid;
                    low=mid+1;
                }
           else{
                high=mid-1;
            }

            
            for(int i=0;i<=mid;i++){
                int r=cells[i][0]-1;
                int c=cells[i][1]-1;
                matrix[r][c]=1;
            }
        }

        return ans+1;
    }
};