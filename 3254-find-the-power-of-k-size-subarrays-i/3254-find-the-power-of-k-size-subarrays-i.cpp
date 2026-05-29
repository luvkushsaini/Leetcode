class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        vector<int>ans(n-k+1,-1);
        while(j<n){
            while(j-i+1>k){
                i++;
            }
           if(j!=0){
            if(nums[j]-nums[j-1]!=1){
                i=j;
            }
           }
           if(j-i+1==k){
            ans[i]=nums[j];
           }
           j++;
        }
        return ans;
    }
};