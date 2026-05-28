class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0;
        int j=0;

        int n=answerKey.size();
        int ct1=0,ct2=0;
        int ans=0;

        while(j<n){
            if(answerKey[j]=='T')ct1++;
            else ct2++;

            while(min(ct1,ct2)>k){
                if(answerKey[i]=='T')ct1--;
                else ct2--;
                i++;
            }
            ans=max(ans,ct1+ct2);
            j++;
        }
        return ans;
    }
};