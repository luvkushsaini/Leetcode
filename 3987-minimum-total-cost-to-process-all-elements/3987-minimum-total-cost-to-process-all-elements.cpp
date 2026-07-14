class Solution {
public:
    const int M=1000000007;
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
        int cost=0;
        int currResources=k;
        long long count=1;
        for(int i=0;i<n;i++){
            if(nums[i]<=currResources){
                currResources-=nums[i];
            }
            else{
                int ct=ceil((double)(nums[i]-currResources)/k);
                currResources+=(ct*k);
                currResources-=nums[i];
                long long x = (2LL * count%M + (ct - 1)%M)%M;
                long long sum = (1LL * ct * x/ 2)%M;
                cost=(cost+sum)%M;
                count=count+ct;
            }
        }

        return cost;
    }
};