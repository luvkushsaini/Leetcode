import java.util.*;

class Solution {

    public boolean canRotateToAsc(int i , int j, int []nums){
    int k=i+1;
    int ct=0;
    while(k<=j){
        if(nums[k]<nums[k-1]){ct++;}
        k++;
    }
    if(nums[i]<nums[j])ct++;

    return (ct<=1);
    }

    public int sortableIntegers(int[] nums) {
        int n = nums.length;

        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            int mn=0;
            boolean ok = true;
            for (int i = 0; i < n; i += k) {
                int j = i+k-1;
                int subarray_mn=Integer.MAX_VALUE;
                int subarray_mx=Integer.MIN_VALUE;
                for(int l=i;l<=(i+k-1);l++){
                    subarray_mn=Math.min(subarray_mn,nums[l]);
                    subarray_mx=Math.max(subarray_mx,nums[l]);
                }

                if(mn>subarray_mn || !canRotateToAsc(i,j,nums)){
                    ok=false;
                    break;
                }
                mn=subarray_mx;
            }

            if (ok) {
                ans += k;
                System.out.println(k);
            }
        }

        return ans;
    }
}