class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mxElement(n);
        int mx=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,nums[i]);
            mxElement[i]=mx;
        }

        int i=0;
        int currMax=0;
        int ans=0;
        int j=k;
        while(j<n){
            currMax=max(nums[i],currMax);
            int mxFromLast=mxElement[j];
            ans=max(ans,currMax+mxFromLast);
            i++;
            j++;
        }

        return ans;
    }
};