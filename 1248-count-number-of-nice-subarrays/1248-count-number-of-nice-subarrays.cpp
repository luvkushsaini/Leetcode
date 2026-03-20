class Solution {
public:
    int n;

    int solve(int k,vector<int>& nums){
        int l=0,r=0,sum=0,count=0;
        while(r<n){
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]%2)nums[i]=1;
            else nums[i]=0;
        }

        int ans=solve(k,nums)-solve( k-1,nums);
        return ans;  
    }
};