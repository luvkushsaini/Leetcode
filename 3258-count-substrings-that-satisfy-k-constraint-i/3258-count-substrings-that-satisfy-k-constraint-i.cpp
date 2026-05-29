class Solution {
public:
    int n;
    int fun(string s,int k){
        int i=0;
        int j=0;
        int ct1=0;
        int ct0=0;
        int count=0;
        while(j<n){
            if(s[j]=='1')ct1++;
            else ct0++;
            while(ct1>k && ct0>k){
                if(s[i]=='1')ct1--;
                else ct0--;
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int countKConstraintSubstrings(string s, int k) {
        n=s.size();
        int ans=fun(s,k);
        return ans;
    }
};