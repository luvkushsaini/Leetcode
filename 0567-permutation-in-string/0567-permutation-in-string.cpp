class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        if(n>m)return false;
        vector<int>v1(26,0),v2(26,0);
        for(int i=0;i<n;i++)v1[s1[i]-'a']++;
        for(int i=0;i<n-1;i++)v2[s2[i]-'a']++;

        int i=0;
        int j=n-1;
        while(j<m){
            v2[s2[j]-'a']++;
            bool flag=true;
            for(int k=0;k<26;k++){
                if(v1[k]!=v2[k]){
                    flag=false;
                    break;
                }
            }
            if(flag)return true;
            v2[s2[i]-'a']--;
            i++;
            j++;
        }
        return false;
    }
};