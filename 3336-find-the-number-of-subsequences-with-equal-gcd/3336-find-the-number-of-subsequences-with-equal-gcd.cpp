class Solution {
public:
    int n;
    const int M=1000000007;
    int dp[201][201][201];
    int solve(int i,int gcd1,int gcd2,vector<int>& nums){
        if(i==n) return (gcd1==gcd2)?1:0;

        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];

         int ans=solve(i+1,gcd1,gcd2,nums)%M;
         ans=(ans+solve(i+1,gcd(gcd1,nums[i]),gcd2,nums)%M)%M;
         ans=(ans+solve(i+1,gcd1,gcd(gcd2,nums[i]),nums)%M)%M;
        return dp[i][gcd1][gcd2]=ans;
    }


    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,nums)-1;//subtracting 1 to exclude the case when both are empty and their gcd is 0 and 0 
    }
};