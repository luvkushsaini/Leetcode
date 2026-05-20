class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int pos=0;

        while(low<=high){
            int mid=(low+high)/2;

            int num=nums[mid];
            if(num>=nums[low]){
                if(target>=nums[low] && target<=num){
                    pos=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target>=num && target<=nums[high]){
                    pos=mid;
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
        }

        if(nums[pos]==target)return pos;
        return -1;
    }
};