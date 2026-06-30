class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())swap(nums1,nums2); // for vectors it takes O(1) time complexity for swapping
        int n=nums1.size();
        int m=nums2.size();

        int size=(n+m);
        int leftNumsCount=(n+m+1)/2;
        int rightNumsCount=size-leftNumsCount;

        int low=0;
        int high=min(leftNumsCount,n);
        int  px,py;


        while(low<=high){
            int mid=(low+(high-low)/2);
             int leftLast1=(mid>0?nums1[mid-1]:INT_MIN);
             int leftLast2=((leftNumsCount-mid)>0?nums2[leftNumsCount-mid-1]:INT_MIN);

             int rightStart1=(mid<n?nums1[mid]:INT_MAX);
             int rightStart2=((leftNumsCount-mid<m)?nums2[leftNumsCount-mid]:INT_MAX);

            if(leftLast1>rightStart2){
                high=mid-1;
            }
            else{
                px=max(leftLast1,leftLast2);
                py=min(rightStart1,rightStart2);

                low=mid+1;
            }
        }

        double ans;
        if(size%2)ans=px;
        else{
            ans=((px+py)/2.0);
        }
        return ans;
    }
};