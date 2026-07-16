class Solution {
public:
  vector<int>nse(string &num){
    int n=num.size();
    vector<int>v(n);
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && num[i]<=num[st.top()])st.pop();
        if(!st.empty())v[i]=st.top();
        if(st.empty())v[i]=n;
        st.push(i);
    }
    return v;
  }
    string removeKdigits(string num, int k) {
        int n=num.size();
        vector<int>nseIndex=nse(num);
        string ans="";
        int i=0;
       while(i<n && k>0){
            if((nseIndex[i]-i)>k ){
                if(ans.size()==0  && num[i]=='0'){
                    i++;
                    continue;
                }
                ans.push_back(num[i]);
                i++;
            }
            else if ((nseIndex[i]-i)<=k){
                k-=(nseIndex[i]-i);
                i=nseIndex[i];
            }
        }

        while(i<n){
            if(ans.size()==0  && num[i]=='0'){
                    i++;
                    continue;
                }
                ans.push_back(num[i]);
                i++;
        }
        if(ans.size()==0)return "0";
        return ans;

    }
};