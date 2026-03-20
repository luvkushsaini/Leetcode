class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>oddPosition;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2)oddPosition.push_back(i);
        }

        int ans=0;

        int i=0;
        int j=k-1;
         
        int size=oddPosition.size();
        while(j<size){
            int num1=(i!=0)?(oddPosition[i]-oddPosition[i-1]):oddPosition[i]+1;
            int num2=(j!=size-1)?(oddPosition[j+1]-oddPosition[j]):n-oddPosition[j];

            ans+=(num1*num2);
            i++;
            j++;
        }

        return ans;
    }
};