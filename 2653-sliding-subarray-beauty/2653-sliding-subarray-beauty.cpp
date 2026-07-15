class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<k-1;i++){
            mp[nums[i]]++;
        }

        int i=0;
        int j=k-1;
        vector<int>ans(n-k+1);

        while(j<n){
            mp[nums[j]]++;
            int ct=x;
            for(auto& [val,freq]:mp){
                if(freq>=ct){
                    ans[i]=((val<0)?val:0);
                    break;
                }
                else ct-=freq;
                
            }
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            i++;
            j++;
        }

        return ans;
    }
};