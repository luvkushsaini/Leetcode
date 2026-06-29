class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string temp=s;
        string rev=s;
        reverse(rev.begin(),rev.end());
        temp+='#';
        temp+=rev;
        int i=1;
        int len=0;
        int size=temp.size();
        vector<int>lps(size,0);
        while(i<size){
            if(temp[i]==temp[len]){
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
       int  palLen=lps.back();
        string ans=s.substr(palLen);
        reverse(ans.begin(),ans.end());
        ans+=s;
        return ans;
    }
};