class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int count=0;
        int ct0=0,ct1=0,ct2=0;

        while(j<n){
            if(s[j]=='a')ct0++;
            else if(s[j]=='b')ct1++;
            else ct2++;

            while(i<=j && ct0>0 && ct1>0 && ct2>0){
                if(s[i]=='a')ct0--;
                else if(s[i]=='b')ct1--;
                else ct2--;
                i++;
            }
            count+=i;
            j++;
        }

        return count;
    }
};