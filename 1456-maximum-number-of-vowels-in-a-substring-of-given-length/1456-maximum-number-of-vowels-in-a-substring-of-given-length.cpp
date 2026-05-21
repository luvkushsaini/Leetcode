class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<int,int>mp;

        int n=s.size();
        for(int i=0;i<k-1;i++){
            if(s[i]=='a' || s[i]== 'e' ||s[i]=='o' || s[i]== 'u' || s[i]=='i'){
                mp[s[i]-'a']++;
            }
        }

        int i=0;
        int j=k-1;
        int ans=0;

        while(j<n){
            if(s[j]=='a' || s[j]== 'e' ||s[j]=='o' || s[j]== 'u' || s[j]=='i'){
                mp[s[j]-'a']++;
            }
            int sum=0;
           for(auto x:mp)sum+=x.second;
           ans=max(ans,sum);
            auto it=mp.find(s[i]-'a');
            if(it!=mp.end()){
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0)mp.erase(s[i]-'a');
            }
            i++;
            j++;
        }

        return ans;
    }
};