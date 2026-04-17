class Solution {

    int pos(int i,List<Integer>list){
        int low=0;
        int high=list.size()-1;
        int ind=list.size();

        while(low<=high){
            int mid=(low+high)/2;

            if(list.get(mid)<=i){
                low=mid+1;
            }
            else {
                ind=mid;
                high=mid-1;
            }
        }
        return ind;
    }
    public int minMirrorPairDistance(int[] nums) {
        int n=nums.length;
        Map<Integer,List<Integer>>mp=new HashMap<>();

        for(int i=0;i<n;i++){
            int num=nums[i];
            mp.putIfAbsent(num,new ArrayList<>());
            mp.get(num).add(i);
        }

        int ans=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            int num1=nums[i];
            String s=String.valueOf(num1).toString();
            String reversed=new StringBuilder(s).reverse().toString();
            int num2=Integer.parseInt(reversed);

            if(!mp.containsKey(num2))continue;
            
            int index=pos(i,mp.get(num2));
            if(index==mp.get(num2).size())continue;
            ans=Math.min(ans,mp.get(num2).get(index)-i);
        }

        return (ans==Integer.MAX_VALUE)?-1:ans;
    }
}