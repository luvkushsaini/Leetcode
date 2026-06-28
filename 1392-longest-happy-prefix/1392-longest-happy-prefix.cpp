class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n);
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
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }

        string ans="";
        for(int i=0;i<lps[n-1];i++)ans.push_back(s[i]);
        return ans;
    }
};