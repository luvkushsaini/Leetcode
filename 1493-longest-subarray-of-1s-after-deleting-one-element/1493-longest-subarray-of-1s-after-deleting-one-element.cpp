class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0;
        int n=nums.size();


        int i=-1;
        int j=-1;
        int ans=0;
        int indexOfZero=-1;
        for(int k=0;k<n;k++){
            if(nums[k]==1){
                i=k;
                j=k;
                indexOfZero=0;
                break;
            }
        }
        if(i==-1 || j==-1)return 0;
        while(j<n){
            while(j<n && nums[j]==1)j++;
            ans=max(ans,(j-i));
            if((i-indexOfZero)==1)ans=max(ans,prev+(j-i));
            prev=((j-i));
            indexOfZero=j;
            while(j<n && nums[j]==0)j++;
            i=j;
        }
        return ans==n?n-1:ans;
        
    }
};