class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int>freq;
        int i=0;
        int j=0; 
        int len=0;

        while(j<n){
            char c=s[j];
            freq[c]++;
            while(i<j && freq[c]>1){
                freq[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }

        return len;
    }
};