class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>par(n);
        for(int i=0;i<n;i++)par[i]=i;
        int mxIndex=0;
        int mx=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    par[i]=j;
                    dp[i]=1+dp[j];
                }
            }
           if(mx<dp[i]){
            mx=dp[i];
            mxIndex=i;
           }
        }

        vector<int>ans;

        int k=mxIndex;

        while(par[k]!=k){
            ans.push_back(nums[k]);
            k=par[k];
        }
        ans.push_back(nums[k]);

        return ans;


        

    }
};