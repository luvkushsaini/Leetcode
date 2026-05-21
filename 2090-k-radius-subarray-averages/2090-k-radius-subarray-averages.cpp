class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long >preffixSum(n,0LL);

        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            preffixSum[i]=sum;
        }


        int i=0;
        int j=2*k;
        vector<int>ans(n,-1);

        while(j<n){
            int centre=i+k;
            long long  value=(preffixSum[j]-(i==0?0:preffixSum[i-1]));
            value/=(2*k+1);
            ans[centre]=(int)value;
            i++;
            j++;
        }
        return ans;
    }
};