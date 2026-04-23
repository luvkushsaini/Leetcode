class Solution {
    public int maxDistance(int[] nums1, int[] nums2) {
        int i=0;
        int j=0;
        int n=nums1.length;
        int m=nums2.length;

        int ans=0;

        while(i<n){

            j=Math.max(j,i);
            while(j<m && nums2[j]>=nums1[i]){
                j++;
            }
            ans=Math.max(ans,j-i-1);
            i++;
        }

        return ans;
    }
}