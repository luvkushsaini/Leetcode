class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>nums;
        int n=grid.size();
        int  m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)if((nums[i]-nums[i-1])%x!=0)return -1;

        int median = nums[nums.size() / 2];
        int ans = 0;
        for(int val : nums) {
            ans += abs(val - median) / x;
        }
        return ans;
    }
};