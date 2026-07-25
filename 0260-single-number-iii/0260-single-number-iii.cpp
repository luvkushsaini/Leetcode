class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int grp1=0;
        int grp2=0;
        int xr=0;

        for(int i=0;i<n;i++){
            xr^=nums[i];
        }
        int diffBit=0;
        for(int i=0;i<32;i++){
            if((xr>>i)&1){
                diffBit=i;
                break;
            }
        }

        for(int i=0;i<n;i++){
            if((nums[i]>>diffBit)&1)grp1^=nums[i];
            else grp2^=nums[i];
        }
        return {grp1,grp2};
    }
};