class Solution {
public:
    string solve(string &s){
        int size=s.size();
        string result="";
        int i=0;
        while(i<size){
            char c=s[i];
            int j=i;
            while(j<size && s[j]==c)j++;
            int ct=j-i;
            char cnt=ct+'0';
            result.push_back(cnt);
            result.push_back(c);
            i=j;
        }

        return result;
    }
    string countAndSay(int n) {
        string result="1";
        int i=1;
        while(i<n){
            result=solve(result);
            i++;
        }
        return result;
    }
};