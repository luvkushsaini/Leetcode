class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int sum,vector<int>&nums,int target){
        if(sum==target){
            return 1;
        }

        if(dp[i][sum]!=-1)return dp[i][sum];

        int count=0;
        for(int k=0;k<nums.size();k++){
            if((sum+nums[k])<=target){
                count+=solve(i+1,sum+nums[k],nums,target);
            }
        }

        return dp[i][sum]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(target+1,vector<int>(target+1,-1));
        return solve(0,0,nums,target);
    }
};