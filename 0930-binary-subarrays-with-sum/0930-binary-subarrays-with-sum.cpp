class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0;

        if(goal==0){
            int count=0;
            int j=0;
            while(j<n){
                if(nums[j]==1){
                    ans+=(count*(count+1))/2;
                    count=0;
                }
                if(nums[j]==0)count++;
                j++;
            }
            ans+=(count*(count+1))/2;
            return ans;
        }
        
        int i=0;
        vector<int>v;
        for(int k=0;k<n;k++){
            if(nums[k]==1){
                v.push_back(k);
                cout<<k<<" ";
            }
        }
        int j=goal-1;
        if(j>=v.size())return 0;

        while(j<v.size()){
            int x1=v[i]-((i==0)?-1:v[i-1]);
            int x2=((j==v.size()-1)?n:v[j+1])-v[j];
            ans+=(x1*x2);
            i++;
            j++;
        }
        return ans;
    }
};