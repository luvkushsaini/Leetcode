class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mx=0;
        int ans=-1;
        int cnt=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
       while(i<n){
            int j=i;
            cnt=0;
            while(j<n && nums[j]==nums[i])j++,cnt++;
            if(cnt>mx){
                mx=cnt;
                ans=nums[i];
            }
            i=j;
        }
        return ans;

    }
};