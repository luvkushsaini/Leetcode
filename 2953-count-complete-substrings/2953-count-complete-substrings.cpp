class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int n=word.size();

        int i=0;
        int j=0;
        vector<int>v;
        int ans=0;
        while(j<n){
            if(j<n-1 && abs(word[j]-word[j+1])<=2){
               j++;
               continue;
            }
            for(int l=1;l<=26;l++){
                int window=k*l;
                if(j-i+1<window)break;
                v.assign(26,0);
                int i1=i;
                int j1=i+window-1;
                for(int m=i1;m<j1;m++)v[word[m]-'a']++;
                while(j1<=j){
                    v[word[j1]-'a']++;
                    bool flag=true;
                    for(int x=0;x<26;x++){
                        if(v[x]!=0 && v[x]!=k){
                            flag=false;
                            break;
                        }
                    }
                    if(flag)ans++;
                    v[word[i1]-'a']--;
                    i1++;
                    j1++;
                }
            }
            j++;
            i=j;
        }
        return ans;
    }
};