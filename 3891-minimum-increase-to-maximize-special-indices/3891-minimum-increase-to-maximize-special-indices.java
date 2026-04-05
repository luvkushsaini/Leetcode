class Solution {

    int n;
    long  [][]dp;
    long   solve(int i,int skip,int [] nums){
        if(i>=n-1)return 0;
        if(dp[i][skip]!=-1L)return dp[i][skip];

        long ans1=Long.MAX_VALUE;
        if(skip==0)ans1=solve(i+1,1,nums);
        long  mx=Math.max(nums[i-1],nums[i+1])-nums[i]+1L;
        long  ans2=(mx>0)?mx:0;
        ans2+=solve(i+2,skip,nums);

        return dp[i][skip]=Math.min(ans1,ans2);

    }
    public long minIncrease(int[] nums) {
        long  ans1=0,ans2=0;
         n=nums.length;
         if(n==2)return 0;
         dp=new long[n][2];
         for(int i=0;i<n;i++){
           Arrays.fill(dp[i],-1L);
         }
        for(int i=1;i<n;i+=2){
            if(i+1==n)break;
            long  mx=Math.max(nums[i-1],nums[i+1]);
            if(nums[i]>mx)continue;
            else {
                if(n%2==0  && n>2 && i==n-3){
                    long  num1=Math.max(nums[i-1],nums[i+1])-nums[i]+1L;
                    long  num2=Math.max(nums[i],nums[i+2])-nums[i+1]+1L;
                    if(num1<=0 || num2<=0)continue;
                    else ans1+=Math.min(num1,num2);
                }
                else ans1+=(mx-nums[i]+1L);
            }
        }

        if(n%2==1)return ans1;

        return solve(1,0,nums);
    }
}