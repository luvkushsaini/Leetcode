class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int i=num1;i<=num2;i++){
            int num=i;
            if(num<100)continue;
            string s=to_string(num);
            for(int j=1;j<=(s.size()-2);j++){
                if(s[j]>s[j-1] && s[j]>s[j+1])ans++;
                else if(s[j]<s[j-1] && s[j]<s[j+1])ans++;
            }
        }

        return ans;
    }
};