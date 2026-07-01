class Solution {
public:
    vector<vector<int>>results;
    int n;
    void twoSum(vector<int>& nums,int target,int start){
        int i=start;
        int j=n-1;

        while(i<j){
            if((nums[i]+nums[j])>target)j--;
            else if((nums[i]+nums[j])<target)i++;
            else{
                results.push_back({-target,nums[i],nums[j]});
                while(i<j && nums[i]==nums[i+1])i++;
                while(i<j && nums[j]==nums[j-1])j--;
                i++;
                j--;
            }

        }

        return ;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0;i<=(n-3);i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            twoSum(nums,-nums[i],i+1);
        }
        return results;
    }
};