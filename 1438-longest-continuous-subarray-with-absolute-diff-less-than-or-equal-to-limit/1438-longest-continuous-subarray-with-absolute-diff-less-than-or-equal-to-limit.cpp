class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int>mp;
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            while(abs(mp.begin()->first-prev(mp.end())->first)>limit){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;

    }
};