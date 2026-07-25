class Solution {
public:
    vector<vector<int>>ans;
    unordered_set<int>st;
    vector<int>v;
    int n;
    void solve(int i,vector<int>v){
        if(i==n)ans.push_back(v);
        vector<int>vec;
        for(int num:st)vec.push_back(num);
        for(int j=0;j<vec.size();j++){
            v.push_back(vec[j]);
            st.erase(vec[j]);
            solve(i+1,v);
            v.pop_back();
            st.insert(vec[j]);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;i++)st.insert(nums[i]);
        solve(0,v);

        return ans;

    }
};