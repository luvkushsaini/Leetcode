class Solution {
    int[][]visited;
    int n,m;
    int []r={-1,1,0,0};
    int []c={0,0,-1,1};
    boolean solve(int i,int j,int p1,int p2,char[][] grid){
        boolean ans=false;
        visited[i][j]=1;

        for(int k=0;k<=3;k++){
            int new_r=i+r[k];
            int new_c=j+c[k];
            if(new_r>=0 && new_r<n && new_c<m && new_c>=0 && (new_r!=p1 || new_c!=p2) && grid[i][j]==grid[new_r][new_c]){
                if(visited[new_r][new_c]==1)return true;
                ans|=solve(new_r,new_c,i,j,grid);
            }
        }
        return ans;
    }
    public boolean containsCycle(char[][] grid) {
        n=grid.length;
        m=grid[0].length;

        visited=new int[n][m];

        boolean ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=1){
                     ans|=solve(i,j,i,j,grid);
                }
               
            }
        }
        return ans;
    }
}