class Solution {
public:
    int minOperations(string s) {
        int first1 = 0,ans1=0,ans2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]-'0' != first1) {
                ans1++;
            }
            else{
                ans2++;
            }
            first1 = !first1;
        }
        return min(ans1,ans2);
    }
};