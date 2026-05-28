class Solution {
public:
    int n;
    vector<long long>prefixSum;
    bool fun(vector<int>& nums, int k,int mid){
        int i=0;
        int j=mid-1;

        while(j<n){
            long long count=0LL;
            long long  num=1LL*nums[j];
            count+=num*(j-i+1)-(prefixSum[j]-((i==0)?0:prefixSum[i-1]));
            if(count<=(1LL*k))return true;
            j++;
            i++;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        prefixSum.assign(n,0LL);
        prefixSum[0]=1LL*nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        int low=1;
        int high=n;

        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(nums,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};