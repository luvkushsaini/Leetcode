class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int>pairs(n);

        sort(potions.begin(),potions.end());

        for(int i=0;i<n;i++){
            int low=0;
            int high=m-1;
            int pos=m;

            while(low<=high){
                int mid=(low+high)/2;

                long long product=1LL*potions[mid]*spells[i];
                if(product>=success){
                    pos=mid;
                    high=mid-1;
                }
                else low=mid+1;
            }

            pairs[i]=m-pos;
        }

        return pairs;

        
    }
};