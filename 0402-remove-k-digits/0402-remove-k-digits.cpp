class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        stack<int>st;
        int i=0;
        char c=2+'0';
        while(i<n){
            int num=s[i];
            while(!st.empty() && st.top()>num && k>0){
                st.pop();
                k--;
            }
            if(st.empty() && num=='0'){
                i++;
                continue;
            }
            st.push(num);
            i++;
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty())ans.push_back(st.top()),st.pop();
        if(ans.size()==0)return "0";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};