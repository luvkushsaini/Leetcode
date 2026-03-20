class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n=fruits.size();
        if(n<=2)return n;
        unordered_map<int,int>mp;
        int l=0,r=0;

        int ans=0;

        while(r<n){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)mp.erase(fruits[l]);
                l++;
            }
            r++;
            int sum=0;
            for(auto &x:mp)sum+=x.second;
            ans=max(sum,ans);
        }

        return ans;
    }
};