class Solution {
public:

    bool KMP(string &repeated,string &b){
        vector<int>lps(b.size());
        lps[0]=0;
        int i=1;
        int len=0;
        while(i<b.size()){
            if(b[i]==b[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
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
        while(i<repeated.size()){
            if(j==b.size())return true;
            if(repeated[i]==b[j]){
                i++;
                j++;
                continue;
            }
            else{
                if(j>0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        if(j==b.size())return true;
        return false;
    }



    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        string repeated="";
        int times=0;

        while(repeated.size()<=(m+n)){
            if(KMP(repeated,b))return times;
            else{
                times++;
                repeated+=a;
            }
        }

        if(KMP(repeated,b))return times;
        return -1;
    }
};