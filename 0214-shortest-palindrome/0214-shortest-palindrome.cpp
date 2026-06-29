class Solution {
public:
//Most optimized O(n) solution using LPS array concept that was used in KMP algo
    
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());

       string a=s;
       a+='#';
       a+=rev;

       int m=a.size();
       vector<int>lps(m);

       //calculating the lps array
       lps[0]=0;
       int j=1;
       int len=0;
       while(j<m){
        if(a[j]==a[len]){
            len++;
            lps[j]=len;
            j++;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else lps[j]=0,j++;
        }
       }
       return rev.substr(0,n-lps[m-1])+s;
    }
};