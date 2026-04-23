class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n=nums.length;
        int []min=new int[n];
        int []max=new int[n];

        int mx=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            mx=Math.max(mx,nums[i]);
            max[i]=mx;
        }
        int mn=Integer.MAX_VALUE;
        for(int i=n-1;i>=0;i--){
            mn=Math.min(mn,nums[i]);
            min[i]=mn;
        }

        int ans=n;

        for(int i=0;i<n;i++){
            int score=max[i]-min[i];
            if(score<=k){
                ans=Math.min(ans,i);
            }
        }

        return (ans==n)?-1:ans;
    }
}