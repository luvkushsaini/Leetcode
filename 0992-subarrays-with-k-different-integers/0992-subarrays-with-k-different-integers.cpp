class Solution {
public:
    int fun(vector<int>& nums, int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(i<n && mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};