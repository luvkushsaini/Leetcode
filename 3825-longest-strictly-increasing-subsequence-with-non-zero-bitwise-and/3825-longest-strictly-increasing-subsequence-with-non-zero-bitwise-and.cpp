class Solution {
public:
    vector<int>res;
    int LisLength(vector<int>&v){
        res.clear();
        res.push_back(v[0]);

        for(int i=1;i<v.size();i++){
            if(v[i]>res.back()){
                res.push_back(v[i]);
                continue;
            }
            int index=lower_bound(res.begin(),res.end(),v[i])-res.begin();
            res[index]=v[i]; 
        }

        return res.size();
    }


    int longestSubsequence(vector<int>& nums) {
        res={};
        int n=nums.size();
        vector<vector<int>>v(31);

        for(int i=0;i<=30;i++){
            for(int j=0;j<n;j++){
                if(nums[j]&(1<<i))v[i].push_back(nums[j]);
            }
        }

        int ans=0;

        for(int i=0;i<=30;i++){
            if(v[i].size()==0)continue;
            ans=max(ans,LisLength(v[i]));
            cout<<LisLength(v[i])<<" ";
        }
        cout<<endl;

        return ans;

        
    }
};