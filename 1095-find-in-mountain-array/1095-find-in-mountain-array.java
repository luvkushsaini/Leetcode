/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n=mountainArr.length();
        int l=0;
        int h=n-1;
        int mountIndex=-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(mountainArr.get(mid)>((mid>0)?mountainArr.get(mid-1):0)){
                mountIndex=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
       // System.out.println(mountIndex);

        l=0;
        h=mountIndex;
        int ans=-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(mountainArr.get(mid)>=target){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        //System.out.println(ans);
        if(ans!=-1 && mountainArr.get(ans)==target)return ans;

        l=mountIndex;
        h=n-1;

        while(l<=h){
            int mid=l+(h-l)/2;

            if(mountainArr.get(mid)>=target){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        System.out.println(ans);

        if(ans!=-1  && mountainArr.get(ans)==target)return ans;
        else return -1;

    }
}