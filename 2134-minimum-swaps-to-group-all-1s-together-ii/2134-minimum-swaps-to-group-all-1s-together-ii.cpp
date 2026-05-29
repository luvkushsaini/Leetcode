class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j;
        int totalone=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)totalone++;
        }
        if(totalone==0)return 0;
        int count=0;
        j=totalone-1;
        for(int i=0;i<j;i++){
            if(nums[i]==1)count++;
        }
       while(j<2*n){
        int ind1=j%n;
        if(nums[ind1]==1)count++;
        mx=max(mx,count);
        int ind2=i%n;
        if(nums[ind2]==1)count--;
        i++;
        j++;
       }
       
       return totalone-mx;
       
    }
};