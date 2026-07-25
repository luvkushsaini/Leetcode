class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int num=0;
        for(int i=0;i<nums.size();i++){
            num^=nums[i];
        }
        return num;
    }
};