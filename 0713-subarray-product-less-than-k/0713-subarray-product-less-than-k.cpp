class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0 || k==1)return 0;
        int product=1;
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;

        while(j<n){
            product*=nums[j];
            while(i<n && product>=k){
                product/=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }

        return ans;

    }
};