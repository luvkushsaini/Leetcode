class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>count(n);
        int ct=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a')ct++;
            count[i]=ct;
        }

        int ans=INT_MAX;
        ct=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a')continue;
            if(s[i]=='b' && count[i]==0)break;
            ans=min(ans,ct+count[i]);
            ct++;
        }
        return min(ct,ans);
    }
};