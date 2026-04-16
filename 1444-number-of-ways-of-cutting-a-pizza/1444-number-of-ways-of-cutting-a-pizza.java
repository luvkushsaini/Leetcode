class Solution {
    int n;
    int m;
    int [][]pre;
    long MOD = 1000000007;
    long [][][]dp;
    long solve(int i,int j,int k){
        if(k==1){
           return (pre[i][j]>0)?1L:0L;
        }

        if(dp[i][j][k]!=-1)return dp[i][j][k];
        long ans=0;
        for(int l=i+1;l<n;l++){
            if((pre[i][j]-pre[l][j])>0){
                ans=(ans+solve(l,j,k-1))%MOD;
            }
        }
        for(int l=j+1;l<m;l++){
            if(pre[i][j]-pre[i][l]>0){
                ans=(ans+solve(i,l,k-1))%MOD;
            }
        }
        return dp[i][j][k]=ans;
    }
    public int ways(String[] pizza, int k) {
        n=pizza.length;
        m=pizza[0].length();
        pre=new int [n+1][m+1];
        dp=new long[n+1][m+1][k+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                Arrays.fill(dp[i][j],-1L);
            }
        }


        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int apple=(pizza[i].charAt(j)=='A')?1:0;
                pre[i][j]=apple+pre[i+1][j]+pre[i][j+1]-pre[i+1][j+1];
            }
        }

        long ans=solve(0,0,k);
        return (int)ans;


    }
}