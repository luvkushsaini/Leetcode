class Solution {

    int n;
    int []suffixSum;
    int []dp;

    int solve(int i){
        if(i>=n)return 0;
        if(dp[i]!=Integer.MIN_VALUE)return dp[i];
        int ans=Integer.MIN_VALUE;
        for(int j=0;j<Math.min(3,n-i);j++){
            int opponent=solve(i+j+1);
            ans=Math.max(ans,suffixSum[i]-opponent);
        }
        return dp[i]=ans;
    }
    public String stoneGameIII(int[] stoneValue) {
        n=stoneValue.length;
        dp=new int[n];
        Arrays.fill(dp,Integer.MIN_VALUE);
        suffixSum=new int[n];
        suffixSum[n-1]=stoneValue[n-1];
        for(int i=n-2;i>=0;i--)suffixSum[i]=suffixSum[i+1]+stoneValue[i];
        int alice=solve(0);
        int bob=suffixSum[0]-alice;
        String ans=new String();
        if(alice>bob)ans="Alice";
        else if(alice<bob)ans="Bob";
        else if(alice==bob)ans="Tie";
        return ans;
    }
}