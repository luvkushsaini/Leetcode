class Solution {
public:
    int n;
    bool fun(vector<int>& position, int m,int mid){
        int count=1;
        int  prev=position[0];
        int i=1;

        while(i<n){
            if(position[i]-prev>=mid){
                count++;
                prev=position[i];
            }
            i++;
        }

        return count>=m;

    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        n=position.size();
        int low=1;
        int high=position[n-1];

        int ans;
        

        while(low<=high){
            int mid=low+(high-low)/2;

            if(fun(position,m,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;


    }
};