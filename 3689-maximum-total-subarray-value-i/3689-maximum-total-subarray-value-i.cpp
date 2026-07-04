class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int diff=mx-mn;

        long long ans=1LL*diff*k;
        return ans;
    }
};