class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        int count=0;
        int i=0;
        int j=0;
        int n=nums.size();
        long long ans=0LL;
        while(j<n){
            if(nums[j]==mx)count++;
            while(count>=k){
                ans+=(n-j);
                if(nums[i]==mx)count--;
                i++;
            }
            j++;
        }

        return ans;
    }
};