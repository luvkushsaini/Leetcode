class Solution {
public:
    int n;

    bool fun(vector<int>& nums, int k, int mid){
        int count=0;
        int i=0;
        while(i<n){
            if(nums[i]<=mid){
                count++;
                i+=2;
            }
            else i++;
        }

        return count>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());

        int ans;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};