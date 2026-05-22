class Solution {
public:

    bool isFun(vector<int>&nums,long long mid){
        long long carry=0;
        for(int i=nums.size()-1;i>=1;i--){
            if(carry+nums[i]<=mid){
                carry=0;
                continue;
            }
            carry=(carry+nums[i])-mid;
        }

        if(carry+nums[0]>mid)return false;
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();

        long long  low=0;
        long long  high=*max_element(nums.begin(),nums.end());
        int ans=high;

        while(low<=high){
            long long  mid=low+(high-low)/2;

            if(isFun(nums,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};