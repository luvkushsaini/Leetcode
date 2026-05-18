class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int ct=0;
        if(k==1)return (r-l)+1;
        int limit=(int)pow(r,1.0/k)+1;
        cout<<limit;
        for(int i=0;i<=limit;i++){
            long long num=(long )pow(i,k);
            if(num>r)break;
            if(num>=l && num<=r)ct++;
        }
        return ct;
    }
};