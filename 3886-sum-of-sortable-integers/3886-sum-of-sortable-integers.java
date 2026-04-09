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

    public boolean areCorrectNumsPresent(int i , int j, int []nums,int []sorted){
        int []arr= new int[j-i+1];
        int ind=0;
        for(int k=i;k<=j;k++){arr[ind]=nums[k];ind++;}
        Arrays.sort(arr);
        ind=0;
        int ind2=i;
        while(ind<arr.length){
            if(arr[ind]!=sorted[ind2]){
                return false;
            }
            ind++;
            ind2++;
        }

        return true;

    }

    public int sortableIntegers(int[] nums) {
        int n = nums.length;

        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            boolean ok = true;
            for (int i = 0; i < n; i += k) {
                int j = i+k-1;
                if(!areCorrectNumsPresent(i,j,nums,sorted) ||!canRotateToAsc(i,j,nums)){
                    ok=false;
                    break;
                }
            }

            if (ok) {
                ans += k;
                System.out.println(k);
            }
        }

        return ans;
    }
}