class Solution {
public:
    int strStr(string haystack, string needle) {
        int n,m;
        n=haystack.size();
        m=needle.size();
        vector<int>lps(m);
        lps[0]=0;
        int len=0;

        int i=1;
        while(i<m){
            if(needle[i]==needle[len]){
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

        i=0;
        int j=0;
        while(i<n){
            if(j==m)return i-m;
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            else{
                if(j!=0){
                j=lps[j-1];
                }
                
                else i++; 
            }
        }

        return -1;
    }
    
};