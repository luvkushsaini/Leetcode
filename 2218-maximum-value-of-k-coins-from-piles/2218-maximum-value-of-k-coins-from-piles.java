class Solution {
    int n;

    int [][]dp;
    int solve(int i,int k,List<List<Integer>> piles){
        if(k==0)return 0;
        if(i>=n){
            if(k==0)return 0;
            else {
                return Integer.MIN_VALUE;
            }
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=solve(i+1,k,piles);
        int sum=0;
        for(int j=0;j<Math.min(k,piles.get(i).size());j++){
            sum+=piles.get(i).get(j);
            ans=Math.max(ans,(sum+solve(i+1,k-(j+1),piles)));
        }
        return dp[i][k]=ans;
    }


    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        n=piles.size();
        dp=new int [n+1][2001];
        for(int i=0;i<n;i++)Arrays.fill(dp[i],-1);
        int ans=solve(0,k,piles);
        return ans;
    }
}