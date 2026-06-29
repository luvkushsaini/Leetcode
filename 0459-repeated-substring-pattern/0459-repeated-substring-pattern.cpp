class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>lps(n,0);

        lps[0]=0;
        int i=1;
        int len=0;

        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    int length = lps[n - 1];

     return length > 0 && n % (n - length) == 0;
    }
};
