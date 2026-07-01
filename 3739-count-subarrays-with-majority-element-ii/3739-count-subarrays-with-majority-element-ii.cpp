class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        long long validPoints=0;
        unordered_map<int,int>mp;
        long long cumSum=0;
        mp[cumSum]=1;
        long long result=0;

        for(int i=0;i<n;i++){
            if(nums[i]==target){
                validPoints+=mp[cumSum];
                cumSum+=1;
            }
            else{
                cumSum-=1;
                validPoints-=mp[cumSum];
            }
            mp[cumSum]++;
            result+=validPoints;
        }

        return result;
    }
};