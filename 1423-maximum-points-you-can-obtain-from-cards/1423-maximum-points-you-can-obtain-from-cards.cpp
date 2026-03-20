class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        int r=n-k-1;   // we will find the sum windwo with  size n-k which has least sum then the rest element left will be the choosen one for max points 

        int sum=0;
        for(int i=0;i<=r;i++)sum+=cardPoints[i];
        int minSum=sum;

        while(r+1<n){
            r++;
            sum+=cardPoints[r];
            sum-=cardPoints[l];
            l++;
            minSum=min(sum,minSum);

        }
        cout<<minSum;

        int totalSum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        return (totalSum-minSum);


    }
};