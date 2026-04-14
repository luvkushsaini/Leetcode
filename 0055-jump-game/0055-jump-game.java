class Solution {
    public boolean canJump(int[] nums) {
        int mxReach=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(i<=mxReach){
                mxReach=Math.max(mxReach,i+nums[i]);
            }
        }
        return mxReach>=n-1?true:false;
    }
}