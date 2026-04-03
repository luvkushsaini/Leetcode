class Solution {
public:
    map<int,int>mp;
    int n;
    set<vector<int>>ans;

    void solve(int i,vector<int>&nums,vector<int>&v){
        if(i==n){
            ans.insert(v);
            return ;
        }

        for(int j=0;j<n;j++){
            if(mp[nums[j]]>0){
                mp[nums[j]]--;
                v.push_back(nums[j]);
                solve(i+1,nums,v);
                v.pop_back();
                mp[nums[j]]++;
            }
        }

        return;
    }
    

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vector<int>v;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

         solve(0,nums,v);

         vector<vector<int>>final_ans(ans.begin(),ans.end());
         return final_ans;
       
        
    }
};