class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int window =min(k,n-1);

        for(int i=0;i<window;i++){
            mp[nums[i]]++;
        }


        int i=0;
        int j=window;

        while(j<n){
            mp[nums[j]]++;
            if(mp.size()<(j-i+1)){
                return true;
            }
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
            j++;
        }

        return false;

    }
};


