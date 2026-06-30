class Solution {
public:
bool KMP(string a, string b) {
        int n=a.size();
        int m=b.size();
        if(n<m)return false;
        vector<int>lps(m);
        lps[0]=0;
        int len=0;
        int j=1;
        while(j<m){
            if(b[len]==b[j]){
                len++;
                lps[j]=len;
                j++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else {
                    lps[j]=0;
                    j++;
                }
            }
        }

        int i=0;
            j=0;
        while(i<n){
            if(a[i]==b[j]){
                i++;
                j++;
            }
             else if(a[i]!=b[j]){
                if(j!=0){
                    j=lps[j-1];
                }
                else i++;
            }
            if(j==m)return true;
        }
        return false;
    }


    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        string repeated=a;
      int times=1;

       while(repeated.size()<b.length()+n){ //max to max the common b in a can start from the last index of the a so we will add a such that it also cover the possiblity of starting the b in a from the last index of a 
        if(KMP(repeated,b))return times;
        else{
            repeated+=a;
            times++;
        }
       }
       if(KMP(repeated,b))return times;
       return -1;
    }
};