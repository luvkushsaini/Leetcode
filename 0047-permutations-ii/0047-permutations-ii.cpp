class Solution {
public:
    // eliminate the condition of duplicacy by sorting the array 
    vector<vector<int>>ans;
    unordered_map<int,int>mp;
    int n;

    void solve(int i,vector<int>&nums,vector<int>&v){
        if(i==n){
            ans.push_back(v);
            return ;
        }

        int j=0;
        while(j<n){
            int num=nums[j];
            if(mp[num]!=0){
                mp[num]--;
                v.push_back(num);
                solve(i+1,nums,v);
                v.pop_back();
                mp[num]++;
            }
            while(j<n && nums[j]==num)j++;
        }

        return;
    }
    

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vector<int>v;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

         solve(0,nums,v);

         return ans;
       
        
    }
};