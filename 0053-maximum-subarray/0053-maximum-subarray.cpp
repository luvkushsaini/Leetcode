class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=nums[0];
        int mxSum=nums[0];
        int n=nums.size();

        for(int i=1;i<n;i++){
            if((currSum+nums[i])<nums[i])currSum=nums[i];
            else currSum+=nums[i];

            mxSum=max(currSum,mxSum);
        }
        return mxSum;
    }
};