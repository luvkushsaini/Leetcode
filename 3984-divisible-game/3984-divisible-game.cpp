class Solution {
public:
    const int M=1000000007;
    vector<bool>isPrime;
    int mx;
    void sieve(){
        isPrime[1]=false;
        isPrime[0]=false;
        for(int i=2;i<=mx+1;i++){
            if(isPrime[i]){
                int j=2;
                int num=i;
                while((num*j)<=(mx+1)){
                    isPrime[num*j]=false;
                    j++;
                }
            }
        }
    }

    
    int divisibleGame(vector<int>& nums) {
        int n=nums.size();
        mx = max(2, *max_element(nums.begin(), nums.end()));
        isPrime.resize(mx+2,true);
        sieve();
        vector<int>prefixSum(n,0);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++) prefixSum[i]=nums[i]+prefixSum[i-1];
        long long ans=0;
        int mxDiff=INT_MIN;

        for(int k=2;k<=mx;k++){
            if(!isPrime[k])continue;
            int i=0;
            long long  sum=0;
            while(i<n){
                int j=i;
                sum=0;
                while(j<n){
                    if(nums[j]%k==0)sum+=nums[j];
                    long long  leftSum=(prefixSum[j]-(i>0?prefixSum[i-1]:0))-sum;
                    long long  diff=sum-leftSum;
                    if(mxDiff<diff){
                        mxDiff=diff;
                        long long score=diff*k;
                        ans=((score%M)+M)%M;
                    }
                    if(diff<0)break;
                    j++;
                }
                i=j+1;
            }
        }

        return (int)ans;
    }
};