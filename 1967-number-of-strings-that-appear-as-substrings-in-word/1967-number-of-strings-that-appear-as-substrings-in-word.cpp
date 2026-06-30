class Solution {
public:

    bool KMP(string &a,string&b){
        int n=a.size();
        int m=b.size();
        vector<int>lps(n);
        lps[0]=0;
        int i=1;
        int len=0;
        while(i<n){
            if(a[i]==a[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len=lps[len-1];
                }
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }


        i=0;
        int j=0;

        while(i<m){
            if(j==n)return true;
            if(a[j]==b[i]){
                i++;
                j++;
                continue;
            }
            else{
                if(j>0){
                    j=lps[j-1];
                }
                else i++;
            }
        }
        if(j==n)return true;
        return false;
    }



    int numOfStrings(vector<string>& patterns, string word) {
        int n=patterns.size();
        int m=word.size();
        int count=0;

        for(int i=0;i<n;i++){
            if(KMP(patterns[i],word))count++;
        }
        return count;
    }
};