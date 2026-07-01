class Solution {
public:
   // there can only me maximum two such numbers possible 
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        
        int curr1=NULL;
        int cnt1=0;

        int curr2=NULL;
        int cnt2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==curr1)cnt1++;
            else if(nums[i]==curr2)cnt2++;
            else if(cnt1==0){
                curr1=nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                curr2=nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        int freq1=0,freq2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==curr1)freq1++;
            else if(nums[i]==curr2)freq2++;
        }

        vector<int>result;
        if(freq1>floor((double)n/3))result.push_back(curr1);
        if(freq2>floor((double)n/3))result.push_back(curr2);

        return result;
    }
};