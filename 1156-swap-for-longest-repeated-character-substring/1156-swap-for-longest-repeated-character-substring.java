class Solution {
    public int maxRepOpt1(String text) {
        int n=text.length();
        List<List<Integer>>alpha=new ArrayList<>();

        for(int i=0;i<26;i++)alpha.add(new ArrayList<>());

        for(int i=0;i<n;i++){
            int ind=text.charAt(i)-'a';
            alpha.get(ind).add(i);
        }

        int mx=1;

        for(int i=0;i<26;i++){
            int cnt1=0;
            int cnt2=0;
            int size=alpha.get(i).size();

            for(int j=0;j<size;j++){
                 if( j==0 || alpha.get(i).get(j)==alpha.get(i).get(j-1)+1)cnt1++;
                else if(alpha.get(i).get(j)==alpha.get(i).get(j-1)+2){
                    cnt2=cnt1;
                    cnt1=1;
                }
                else if(alpha.get(i).get(j)>alpha.get(i).get(j-1)+2){
                    cnt1=1;
                    cnt2=0;
                }

                mx=Math.max(mx,cnt1+((size>(cnt1+cnt2))?(cnt2+1):0));
            }
        }

        return mx;
    }
}