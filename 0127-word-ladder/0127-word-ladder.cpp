class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        unordered_set<string>st(wordList.begin(),wordList.end());

        queue<string>q;
        q.push(beginWord);
        int ans=0;
        int level=1;
        while(!q.empty()){
            int size=q.size();

            while(size--){
            string s=q.front();
            q.pop();
            if(s==endWord){
              return level;
            }

            for(int i=0;i<n;i++){
                char c=s[i];
                for(int j=0;j<26;j++){
                    s[i]='a'+j;
                    if(st.find(s)!=st.end()){
                        q.push(s);
                        st.erase(s);
                    }
                }
                s[i]=c;
            }

            }
            level++;
        }
        return 0;
    }

};