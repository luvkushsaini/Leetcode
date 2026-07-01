class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int currElement=nums[0];
        int cnt=0;

        for(int i=0;i<n;i++){
            if(cnt==0)currElement=nums[i];
            if(nums[i]==currElement)cnt++;
            else cnt--;
        }

        return currElement;
    }
};