class Solution {
public:
    int fun(vector<int>& nums, int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            while(i<n && sum>k){
                sum-=nums[i];
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-((goal!=0)?fun(nums,goal-1):0);
    }
};