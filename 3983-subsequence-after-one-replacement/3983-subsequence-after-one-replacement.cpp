class Solution {
public:
    bool canMakeSubsequence(string s,string t){
        int n=s.size();
        int m=t.size();

        if(n>m)return false;

        vector<int>left(n,m);
        vector<int>right(n,-1);

        int i=0,j=0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                left[i]=j;
                i++;
            }
            j++;
        }

        if(left[n-1]!=m)return true;

        i=n-1;
        j=m-1;
        while(i>=0 && j>=0){
            if(s[i]==t[j]){
                right[i]=j;
                i--;
            }
            j--;
        }

        for(int i=0;i<n;i++){
            if(i==0){
                if(n==1)return true;
                if(right[1]>0)return true;
            }
            else if(i==n-1){
                if(left[n-2]<m-1)return true;
            }
            else{
                if(left[i-1]!=m && right[i+1]!=-1 && right[i+1]-left[i-1]>1)
                    return true;
            }
        }

        return false;
    }
};