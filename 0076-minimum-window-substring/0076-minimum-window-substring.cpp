class Solution {
public:
     int Index(char c){
        if(c>='A' && c<='Z'){
            return c-'A'+26;
        }
        else return  c-'a';
     }

    string minWindow(string s, string t) {
        vector<pair<int,int>>v(52,{0,0});

        for(int k=0;k<t.size();k++){
            int index=Index(t[k]);
            v[index].second++;
        }

        int i=0,j=0;
        int num=INT_MAX;
       int p1=0;
       int formed=0;
        while(j!=s.size()){
            int pos1=Index(s[j]);
            v[pos1].first++;
            if(v[pos1].first<=v[pos1].second && v[pos1].second!=0)formed++;

            while(i<=j && formed==t.size()){
                if((j-i+1)<num){
                    num=j-i+1;
                    p1=i;
                }
                int pos2=Index(s[i]);
                v[pos2].first--;
                i++;
                if(v[pos2].first<v[pos2].second)formed--;
            }
            j++;
        }

        if(num==INT_MAX)return "";
        else return s.substr(p1,num);


    }
};