class Solution {
public:
    const int M=1000000007;
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextSmaller(n,n);
        vector<int>prevSmaller(n,-1);
        stack<int>st;

        int i=0;
        while(i<n){
            int num=nums[i];
            while(!st.empty() && nums[st.top()]>num)st.pop();
            if(!st.empty())prevSmaller[i]=st.top();
            st.push(i);
            i++;
        }
        while(!st.empty())st.pop();


        int j=n-1;
        while(j>=0){
            int num=nums[j];
            while(!st.empty() && nums[st.top()]>=num)st.pop();
            if(!st.empty())nextSmaller[j]=st.top();
            st.push(j);
            j--;
        }



        int ans=0;

        for(int i=0;i<n;i++){
            long long  ct=(1LL*(i-prevSmaller[i])*(nextSmaller[i]-i));
            ct%=M;
            ct=ct*nums[i];
            ans=(ans+ct%M)%M;
           
        }
        return ans;
    }
};