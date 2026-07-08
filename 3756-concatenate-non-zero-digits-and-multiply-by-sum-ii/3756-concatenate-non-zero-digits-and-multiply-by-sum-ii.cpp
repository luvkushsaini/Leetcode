class Solution {
public:
    const int M=1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>prefixSum(n,0);
        vector<int>prefVal(n,0);
        vector<int>prefCnt(n,0);
        vector<int>power(n+1,1);
        for(int i=1;i<=n;i++)power[i]=(1LL*power[i-1]*10)%M;
        int digitCount=0;
        int digit=s[0]-'0';
        prefixSum[0]=digit;
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            prefixSum[i]=digit+prefixSum[i-1];
        }
        int mul=1;
        prefVal[0]=digit;
        prefCnt[0]=1;
        for(int i=1;i<n;i++){
            int digit=s[i]-'0';
            if(digit==0){
                prefVal[i]=prefVal[i-1];
                prefCnt[i]=prefCnt[i-1];
            }
            else{
                prefCnt[i]=prefCnt[i-1]+1;
                prefVal[i]=((1LL*10*prefVal[i-1])%M+digit)%M;
            }
        }

        vector<int>ans(queries.size());

        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            
            int digit_count=prefCnt[r]-(l>0?prefCnt[l-1]:0);
            int mul=power[digit_count];
            int num=(prefVal[r]-(1LL*(l>0?prefVal[l-1]:0)*mul)%M+M)%M;
            int sum=prefixSum[r]-(l>0?prefixSum[l-1]:0);
            ans[i]=(1LL*num*sum)%M;
        }

        return ans;



    }
};