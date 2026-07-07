class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=n;
        int num=0;
        int mul=1;
        int sum=0;
        while(x>0){
            int rem=x%10;
            sum+=rem;
            if(rem!=0){
                num+=(rem*mul);
                mul*=10;
            }
            x-=rem;
            x/=10;
        }
        long long ans=1LL*sum*num;
        return ans;
    }
};