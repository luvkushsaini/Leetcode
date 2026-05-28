class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;

        int i=0;
        int j=k-1;
        map<int,int,greater<int>>mp;
        for(int k=0;k<j;k++){
            int num=nums[k];
            mp[num]++;
        }

        while(j<n){
            mp[nums[j]]++;
            auto it=mp.begin();
            ans.push_back(it->first);
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
            j++;
        }

        return ans;

    }
};