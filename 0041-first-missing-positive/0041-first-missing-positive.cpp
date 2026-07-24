class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     int n=nums.size();
     bool onePresent=false;
     for(int i=0;i<n;i++){
        if(nums[i]==1){
            onePresent=true;
            break;
        }
     }
     if(!onePresent)return 1; 
     for(int i=0;i<n;i++){
        if(nums[i]<=0 || nums[i]>n)nums[i]=1;
     }   

     for(int i=0;i<n;i++){
        int pos=abs(nums[i])-1;
        if(nums[pos]<0)continue;
        nums[pos]=-nums[pos];
     }

     int ans=n+1;
     for(int i=0;i<n;i++){
     if(nums[i]>0)return i+1;
    }
    return ans;
    }
};