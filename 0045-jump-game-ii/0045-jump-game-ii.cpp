class Solution {
public:
    vector<int>dp;
    int n;
    int solve(int i,vector<int>&nums){
        if(i==n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        if(nums[i]==0)return INT_MAX;

        int count=INT_MAX;
        int len=nums[i];
        for(int j=1;j<=len;j++){
            if(i+j>=n)break;
            int fn=solve(i+j,nums);
            count=min(count,fn);
        }
        return dp[i]=(count==INT_MAX)?INT_MAX:(count+1);
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,-1);
        return solve(0,nums);
    }
};