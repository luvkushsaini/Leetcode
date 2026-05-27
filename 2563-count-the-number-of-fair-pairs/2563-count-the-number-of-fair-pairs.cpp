class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        long long count=0;
        for(int i=0;i<n;i++){
            int x1=lower-nums[i];
            int x2=upper-nums[i];
            int ind1=upper_bound(nums.begin(),nums.end(),x2)-nums.begin();
            int ind2=lower_bound(nums.begin(),nums.end(),x1)-nums.begin();
            if(ind1<=i)ind1=i+1;
            if(ind2<=i)ind2=i+1;
            count+=(ind1-ind2);
        }

        return count;

    }
};