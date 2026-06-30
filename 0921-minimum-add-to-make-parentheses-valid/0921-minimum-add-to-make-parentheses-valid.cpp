class Solution {
public:
    int minAddToMakeValid(string s) {
        int ct=0;
        int type=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')type++;
            else {
                if(type>0)type--;
                else ct++;
            }
        }
        return (ct+type);
    }
};