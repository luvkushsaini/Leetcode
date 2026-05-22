class Solution {
public:
    
    long long fun(vector<int>& nums, vector<int>& cost, int mid){
        long long totalCost=0LL;
        for(int i=0;i<nums.size();i++){
            totalCost+=1LL*abs(nums[i]-mid)*cost[i];
         }
            return totalCost;
    }


    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();

        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;

            long long  val1=fun(nums,cost,mid);
            long long val2=fun(nums,cost,mid+1);

            if(val1>val2){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }

        long long totalCost=fun(nums,cost,ans);
        return totalCost;
    }
};