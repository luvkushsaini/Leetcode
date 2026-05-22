class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int low=0;
        int high=n-1;
        int index=0;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]>=target){
                index=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return (nums[index]==target?index:-1);
    }
};