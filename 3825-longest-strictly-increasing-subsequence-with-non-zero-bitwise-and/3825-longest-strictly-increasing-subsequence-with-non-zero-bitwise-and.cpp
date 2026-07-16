class Solution {
public:

    vector<int>res;
    int LIS(vector<int>&v){
        int n=v.size();
        res.clear();

        for(int i=0;i<n;i++){
            if(res.size()==0 || res.back()<v[i])res.push_back(v[i]);
            else if(res.size()!=0 && res.back()>v[i]){
                int ind=lower_bound(res.begin(),res.end(),v[i])-res.begin();
                res[ind]=v[i];
            }
        }

        return res.size();
    }
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>v(32);
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
            if((nums[j]>>i)&1)v[i].push_back(nums[j]);
            }
        }

        int ans=0;
        for(int i=0;i<32;i++){
            ans=max(ans,LIS(v[i]));
        }
        return ans;
    }
};