class Solution {
    int n;
    int []dp;
    int solve(int i,int []nums){
        if(i>n-1)return 0;
        if(i==n-1)return 1;
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        int maxJump=nums[i];

        for(int j=1;j<=maxJump;j++){
            ans|=solve(i+j,nums);
            if(ans==1)break;
        }
        return dp[i]=ans;
    }
    public boolean canJump(int[] nums) {
        n=nums.length;
        dp=new int[n+1];
        Arrays.fill(dp,-1);

        int ans=solve(0,nums);

        return (ans==1)?true:false;
    }
}