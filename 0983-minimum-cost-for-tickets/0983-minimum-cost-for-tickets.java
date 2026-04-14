class Solution {

    int []dp;
    int ind(int num,int []days){
        int i=0;
        int j=days.length-1;
        int index=days.length;

        while(i<=j){
            int mid=(i+j)/2;
            if(days[mid]<=num){
                i=mid+1;
            }
            else{
                index=mid;
                j=mid-1;
            }
        }
        return index;
    }


    int solve(int i,int []days,int []costs){
        if(i>=days.length)return 0;

        if(dp[i]!=-1)return dp[i];

        int ans=costs[0]+solve(i+1,days,costs);
        int ind1=ind(days[i]+6,days);
        int ind2=ind(days[i]+29,days);
        ans=Math.min(ans,costs[1]+solve(ind1,days,costs));
        ans=Math.min(ans,costs[2]+solve(ind2,days,costs));

        return dp[i]=ans;
    }
    public int mincostTickets(int[] days, int[] costs) {
        Arrays.sort(days);
        int n=days.length;
        dp=new int[n];
        Arrays.fill(dp,-1);

        return solve(0,days,costs);

    }
}