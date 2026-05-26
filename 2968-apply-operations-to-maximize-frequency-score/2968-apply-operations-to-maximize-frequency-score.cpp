class Solution {
public:
    int n;
    vector<long long>prefixSum;

    bool fun(int mid,vector<int>& nums, long long k){
        int i=0;
        int j=mid-1;


        while(j<n){
            int ind=(i+j)/2;
            long long  median=nums[ind];
            long long  operations=0LL;
            long long sum1=prefixSum[ind]-((i>0)?prefixSum[i-1]:0);
            long long  req1=(ind-i+1)*median-sum1;

            long long sum2=prefixSum[j]-prefixSum[ind];
            long long  req2=sum2-(j-ind)*median;

            operations+=(req1+req2);
            if(operations<=k)return true;
            i++;
            j++;
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        prefixSum.assign(n,0LL);
        for(int i=0;i<n;i++){
            prefixSum[i]=((i>0)?prefixSum[i-1]:0)+1LL*nums[i];
        }

        int low=1;
        int high=n;
        int ans;


        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(mid,nums,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};