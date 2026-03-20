class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>charCount(26,0);
        int n=s.size();
        int l=0,r=0,ans=0;

        while(r<n){
            charCount[s[r]-'A']++;
            int mx=*max_element(charCount.begin(),charCount.end());
            int restNumCount=r-l+1-mx;
            while(restNumCount>k){
                charCount[s[l]-'A']--;
                l++;
                mx=*max_element(charCount.begin(),charCount.end());
                restNumCount=r-l+1-mx;
            }
            ans=max(ans,(r-l+1));
            r++;
        }

        return ans;


    }
};