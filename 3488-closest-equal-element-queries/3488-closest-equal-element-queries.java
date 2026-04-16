class Solution {

    int pos(int i,List<Integer>list){
        int low=0;
        int high=list.size()-1;
        int ind=0;

        while(low<=high){
            int mid=(low+high)/2;

            if(list.get(mid)>i){
                high=mid-1;
            }
            else{
                ind=mid;
                low=mid+1;
            }
        }

        return ind;
    }

    public List<Integer> solveQueries(int[] nums, int[] queries) {
        int n=nums.length;
        Map<Integer,List<Integer>>mp=new HashMap<>();

        for(int i=0;i<n;i++){
            mp.putIfAbsent(nums[i],new ArrayList<>());
            mp.get(nums[i]).add(i);
        }

        List<Integer>result=new ArrayList<>();

        for(int i=0;i<queries.length;i++){
            int index=queries[i];
            int num=nums[index];
            if(mp.get(num).size()<2){
                result.add(-1);
                continue;
            }

            int size=mp.get(num).size();
            int ind=pos(index,mp.get(num));
            System.out.print(ind);
            if(ind==0){
                int ct=(n-mp.get(num).get(size-1)+index);
                int p=(size>(ind+1))?mp.get(num).get(ind+1)-index:ct;
                ct=Math.min(ct,p);
                result.add(ct);
            }
            else if(ind==size-1){
                int ct=(mp.get(num).get(0)+n-index);
                int p=((ind-1)>=0)?index-mp.get(num).get(ind-1):ct;
                ct=Math.min(ct,p);
                result.add(ct);
            }
            else if(ind!=0 && ind!=size-1){
                int ct=mp.get(num).get(ind)-mp.get(num).get(ind-1);
                ct=Math.min(ct,mp.get(num).get(ind+1)-mp.get(num).get(ind));
                result.add(ct);
            }

        }
        return result;
    }
}